const fs = require("fs");

const wasmAsBase64 = fs.readFileSync("./cdflib.wasm", "base64");
const standaloneTemplate = fs.readFileSync(
  "./cdflibStandalone.template.js",
  "utf8"
);

fs.writeFileSync("./cdflib.wasm.base64.json", JSON.stringify(wasmAsBase64));

fs.writeFileSync(
  "./cdflibStandalone.js",
  "// == AUTO-GENERATED FILE ==\n\n" +
    standaloneTemplate.replace("{{WASM_CODE}}", wasmAsBase64)
);
