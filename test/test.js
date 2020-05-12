const CdfLibWrapper = require("../cdflibNode");

// execute syncronously = true
// Async operation don't work properly in Apps Scripts
// https://stackoverflow.com/questions/61190809/running-async-functions-on-google-apps-script
const cdflibPower = new CdfLibWrapper(true);

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
