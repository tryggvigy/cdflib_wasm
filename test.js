const cdflib = require("./a.out.js");

cdflib.onRuntimeInitialized = () => {
  let which = 1;
  let p = 0.0;
  let q = 0.0;
  let t = 2.10092204024096;
  let df = 18.0;
  let nc = 1.42445665344;
  let status = 10;
  let bound = 0.0;
  // cdflib._cdftnc(which, p, q, t, df, nc, status, bound);
  // cdflib.ccall(
  //   "cdftnc",
  //   "void",
  //   [
  //     "number",
  //     "number",
  //     "number",
  //     "number",
  //     "number",
  //     "number",
  //     "number",
  //     "number"
  //   ],
  //   [which, p, q, t, df, nc, status, bound]
  // );
  console.log(cdflib._cdftnc_power(which, p, q, t, df, nc, status, bound));
  console.log(cdflib._cdft_power(which, p, q, t, df, status, bound));
  // console.log(111111, cdflib._cdftnc(1, 0.0, 0.0, t, df, nc, 10, 0.0))
  // console.log(111111, cdflib._alngam(1.0))
  // console.log(111111, cdflib._esum(1, 2.0));
};
