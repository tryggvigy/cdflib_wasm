const TOTAL_STACK = 1024 * 1024; // 1MB
const TOTAL_MEMORY = 2 * 1024 * 1024; // 1MB
const WASM_PAGE_SIZE = 64 * 1024; // Defined in WebAssembly specs

// The {{}} block is a placeholder that gets
// replaced with the wasm binary as a base64 string.
const WASM_CODE = "{{WASM_CODE}}";

function _base64ToArrayBuffer(base64) {
  var binary_string = atob(base64);
  var len = binary_string.length;
  var bytes = new Uint8Array(len);
  for (var i = 0; i < len; i++) {
    bytes[i] = binary_string.charCodeAt(i);
  }
  return bytes.buffer;
}

class CdfLibWrapper {
  constructor({ compileSync = false } = {}) {
    // Initialize the runtime's memory
    this._wasmMemory = new WebAssembly.Memory({
      initial: TOTAL_MEMORY / WASM_PAGE_SIZE,
      maximum: TOTAL_MEMORY / WASM_PAGE_SIZE,
    });

    this._HEAP8 = new Int8Array(this._wasmMemory.buffer);
    this._HEAP16 = new Int16Array(this._wasmMemory.buffer);
    this._HEAP32 = new Int32Array(this._wasmMemory.buffer);
    this._HEAPF32 = new Float32Array(this._wasmMemory.buffer);
    this._HEAPF64 = new Float64Array(this._wasmMemory.buffer);

    // Compile and export program
    if (compileSync) {
      // compile synchronously
      const program = this._compileSync();
      this._exportProgram(program);

      // create a dummy compile promise
      this.compiled = Promise.resolve();
    } else {
      // create a singleton compile promise
      this.compiled = this._compileAsync().then((program) =>
        this._exportProgram(program)
      );
    }
  }

  asciiToString(ptr) {
    let str = "";
    while (1) {
      const ch = this._HEAP8[ptr++ >> 0];
      if (ch === 0) return str;
      str += String.fromCharCode(ch);
    }
  }

  _mtherr(
    name /* char* */,
    status /* int */,
    bound /* double */,
    result /* double */
  ) {
    let codemsg = "";
    if (status < 0) {
      codemsg = `(C Lang) input parameter ${-status} is out of range`;
    } else {
      switch (status) {
        case 0:
          // No error. Should never be called with status 0
          return result;
        case 1:
          codemsg = `Answer appears to be lower than lowest search bound (${bound})`;
          break;
        case 2:
          codemsg = `Answer appears to be higher than greatest search (${bound})`;
          break;
        case 3:
        case 4:
          codemsg = "Two parameters that should sum to 1.0 do not";
          break;
        case 10:
          codemsg = "Computational error";
          break;
        default:
          codemsg = "Unknown error";
      }
    }

    const fnName = this.asciiToString(name);
    const message = `cdflib reports "${codemsg}" in ${fnName}`;

    if (status < 0 || status === 1 || status === 2) {
      throw new RangeError(message);
    } else {
      throw new Error(message);
    }
  }

  _wasmImports() {
    return {
      env: {
        mtherr: this._mtherr.bind(this),
        memory: this._wasmMemory,
        table: new WebAssembly.Table({
          initial: 8,
          maximum: 8 + 0,
          element: "anyfunc",
        }),
        STACKTOP: 0,
        STACK_MAX: TOTAL_STACK,
        emscripten_memcpy_big() {},
        emscripten_resize_heap() {},
        __handle_stack_overflow() {},
        setTempRet0() {},
        exit() {},
      },
      wasi_snapshot_preview1: {
        fd_close() {},
        fd_write() {},
        fd_seek() {},
      },
    };
  }

  _compileSync() {
    return new WebAssembly.Instance(
      new WebAssembly.Module(WASM_CODE),
      this._wasmImports()
    );
  }

  _compileAsync() {
    return WebAssembly.instantiate(WASM_CODE, this._wasmImports()).then(
      (results) => results.instance
    );
  }

  _exportProgram(program) {
    // export cdflib functions
    for (const key of Object.keys(program.exports)) {
      if (key.startsWith("cdflib_")) {
        const funcNameWithoutPrefix = key.replace("cdflib_", "");
        this[funcNameWithoutPrefix] = program.exports[key];
      }
    }

    // export special stack functions
    this.stackAlloc = program.exports.stackAlloc;
    this.stackRestore = program.exports.stackRestore;
    this.stackSave = program.exports.stackSave;
  }

  // export helper functions
  getValue(ptr, type) {
    type = type || "i8";
    if (type.charAt(type.length - 1) === "*") type = "i32"; // pointers are 32-bit
    switch (type) {
      case "i1":
        return this._HEAP8[ptr >> 0];
      case "i8":
        return this._HEAP8[ptr >> 0];
      case "i16":
        return this._HEAP16[ptr >> 1];
      case "i32":
        return this._HEAP32[ptr >> 2];
      case "i64":
        return this._HEAP32[ptr >> 2];
      case "float":
        return this._HEAPF32[ptr >> 2];
      case "double":
        return this._HEAPF64[ptr >> 3];
      default:
        throw new Error("invalid type for getValue: " + type);
    }
  }

  writeArrayToMemory(array, buffer) {
    this._HEAP8.set(array, buffer);
  }
}

module.exports = CdfLibWrapper;
