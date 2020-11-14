const fs = require("fs");

const wasmAsBase64 = fs.readFileSync("./out/cdflib.wasm", "base64");
const template = fs.readFileSync("./cdflibTemplate.js", "utf8");

fs.writeFileSync("./out/cdflib.wasm.base64.json", JSON.stringify(wasmAsBase64));

fs.writeFileSync(
  "./out/cdflibStandalone.js",
  "// == AUTO-GENERATED FILE ==\n\n" +
    template.replace(
      '"{{WASM_CODE}}"',
      `_base64ToArrayBuffer("${wasmAsBase64}")`
    )
);

fs.writeFileSync(
  "./out/cdflibNode.js",
  "// == AUTO-GENERATED FILE ==\n\n" +
    template.replace(
      '"{{WASM_CODE}}"',
      'Buffer.from(require("./cdflib.wasm.base64"), "base64")'
    )
);
