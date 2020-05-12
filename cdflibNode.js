const TOTAL_STACK = 1024 * 1024; // 1MB
const TOTAL_MEMORY = 2 * 1024 * 1024; // 1MB
const WASM_PAGE_SIZE = 64 * 1024; // Defined in WebAssembly specs

/**
 * Implementation of atob() according to the HTML and Infra specs, except that
 * instead of throwing INVALID_CHARACTER_ERR we return null.
 */
function atobb(data) {
  // Web IDL requires DOMStrings to just be converted using ECMAScript
  // ToString, which in our case amounts to using a template literal.
  data = `${data}`;
  // "Remove all ASCII whitespace from data."
  data = data.replace(/[ \t\n\f\r]/g, "");
  // "If data's length divides by 4 leaving no remainder, then: if data ends
  // with one or two U+003D (=) code points, then remove them from data."
  if (data.length % 4 === 0) {
    data = data.replace(/==?$/, "");
  }
  // "If data's length divides by 4 leaving a remainder of 1, then return
  // failure."
  //
  // "If data contains a code point that is not one of
  //
  // U+002B (+)
  // U+002F (/)
  // ASCII alphanumeric
  //
  // then return failure."
  if (data.length % 4 === 1 || /[^+/0-9A-Za-z]/.test(data)) {
    return null;
  }
  // "Let output be an empty byte sequence."
  let output = "";
  // "Let buffer be an empty buffer that can have bits appended to it."
  //
  // We append bits via left-shift and or.  accumulatedBits is used to track
  // when we've gotten to 24 bits.
  let buffer = 0;
  let accumulatedBits = 0;
  // "Let position be a position variable for data, initially pointing at the
  // start of data."
  //
  // "While position does not point past the end of data:"
  for (let i = 0; i < data.length; i++) {
    // "Find the code point pointed to by position in the second column of
    // Table 1: The Base 64 Alphabet of RFC 4648. Let n be the number given in
    // the first cell of the same row.
    //
    // "Append to buffer the six bits corresponding to n, most significant bit
    // first."
    //
    // atobLookup() implements the table from RFC 4648.
    buffer <<= 6;
    buffer |= atobLookup(data[i]);
    accumulatedBits += 6;
    // "If buffer has accumulated 24 bits, interpret them as three 8-bit
    // big-endian numbers. Append three bytes with values equal to those
    // numbers to output, in the same order, and then empty buffer."
    if (accumulatedBits === 24) {
      output += String.fromCharCode((buffer & 0xff0000) >> 16);
      output += String.fromCharCode((buffer & 0xff00) >> 8);
      output += String.fromCharCode(buffer & 0xff);
      buffer = accumulatedBits = 0;
    }
    // "Advance position by 1."
  }
  // "If buffer is not empty, it contains either 12 or 18 bits. If it contains
  // 12 bits, then discard the last four and interpret the remaining eight as
  // an 8-bit big-endian number. If it contains 18 bits, then discard the last
  // two and interpret the remaining 16 as two 8-bit big-endian numbers. Append
  // the one or two bytes with values equal to those one or two numbers to
  // output, in the same order."
  if (accumulatedBits === 12) {
    buffer >>= 4;
    output += String.fromCharCode(buffer);
  } else if (accumulatedBits === 18) {
    buffer >>= 2;
    output += String.fromCharCode((buffer & 0xff00) >> 8);
    output += String.fromCharCode(buffer & 0xff);
  }
  // "Return output."
  return output;
}
/**
 * A lookup table for atob(), which converts an ASCII character to the
 * corresponding six-bit number.
 */
function atobLookup(chr) {
  if (/[A-Z]/.test(chr)) {
    return chr.charCodeAt(0) - "A".charCodeAt(0);
  }
  if (/[a-z]/.test(chr)) {
    return chr.charCodeAt(0) - "a".charCodeAt(0) + 26;
  }
  if (/[0-9]/.test(chr)) {
    return chr.charCodeAt(0) - "0".charCodeAt(0) + 52;
  }
  if (chr === "+") {
    return 62;
  }
  if (chr === "/") {
    return 63;
  }
  // Throw exception; should not be hit in tests
  return undefined;
}

const WASM_CODE = Buffer.from(require("./cephes.wasm.base64.json"), "base64");

function _base64ToArrayBuffer(base64) {
  var binary_string = atobb(base64);
  var len = binary_string.length;
  var bytes = new Uint8Array(len);
  for (var i = 0; i < len; i++) {
    bytes[i] = binary_string.charCodeAt(i);
  }
  return bytes.buffer;
}

class CdfLibPowerWrapper {
  constructor(sync) {
    // Initialize the runtime's memory
    this._wasmMemory = new WebAssembly.Memory({
      initial: TOTAL_MEMORY / WASM_PAGE_SIZE,
      maximum: TOTAL_MEMORY / WASM_PAGE_SIZE
    });

    this._HEAP8 = new Int8Array(this._wasmMemory.buffer);
    this._HEAP16 = new Int16Array(this._wasmMemory.buffer);
    this._HEAP32 = new Int32Array(this._wasmMemory.buffer);
    this._HEAPF32 = new Float32Array(this._wasmMemory.buffer);
    this._HEAPF64 = new Float64Array(this._wasmMemory.buffer);

    // Compile and export program
    if (sync) {
      // compile synchronously
      const program = this._compileSync();
      this._exportProgram(program);

      // create a dummy compile promise
      this.compiled = Promise.resolve();
    } else {
      // create a singleton compile promise
      this.compiled = this._compileAsync().then(program =>
        this._exportProgram(program)
      );
    }
  }

  _AsciiToString(ptr) {
    let str = "";
    while (1) {
      const ch = this._HEAP8[ptr++ >> 0];
      if (ch === 0) return str;
      str += String.fromCharCode(ch);
    }
  }

  _wasmImports() {
    return {
      env: {
        // memory
        memory: new WebAssembly.Memory({
          initial: 256,
          maximum: 256
        }),
        table: new WebAssembly.Table({
          initial: 8,
          maximum: 8 + 0,
          element: "anyfunc"
        }),
        STACKTOP: 0,
        STACK_MAX: TOTAL_STACK,
        emscripten_memcpy_big() {},
        emscripten_resize_heap() {},
        __handle_stack_overflow() {},
        setTempRet0() {},
        exit() {}
      },
      wasi_snapshot_preview1: {
        fd_close() {},
        fd_write() {},
        fd_seek() {}
      }
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
      results => results.instance
    );
  }

  _exportProgram(program) {
    // export cephes functions
    for (const key of Object.keys(program.exports)) {
      if (key.startsWith("cdf")) {
        this[key] = program.exports[key];
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
    return null;
  }

  writeArrayToMemory(array, buffer) {
    this._HEAP8.set(array, buffer);
  }
}

// execute syncronously = true
// Async operation don't work properly in Apps Scripts
// https://stackoverflow.com/questions/61190809/running-async-functions-on-google-apps-script
const cdflibPower = new CdfLibPowerWrapper(true);

/**
 * Calculate non-central t-distribution power
 *
 * @customfunction
 */
function cdftnc_power(t, df, nc) {
  let which = 1;
  let p = 0.0;
  let q = 0.0;
  let status = 10;
  let bound = 0.0;
  return cdflibPower.cdftnc_power(which, p, q, t, df, nc, status, bound);
}

/**
 * Calculate t-distribution power
 *
 * @customfunction
 */
function cdft_power(p, df) {
  let which = 2;
  let p1 = 0.025;
  let q = 0.975;
  let t = 0.0;
  let df1 = 18.0;
  let status = 10;
  let bound = 0.0;
  return cdflibPower.cdft_power(which, p1, q, t, df1, status, bound);
}

let p = 0.05 / 2;
let t = 2.10092204024096;
let df = 18.0;
let nc = 1.42445665344;
console.log(cdftnc_power(t, df, nc));
console.log(cdft_power(p, df));
