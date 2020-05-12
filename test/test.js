const CdfLibWrapper = require("../cdflibNode");

expect.extend({
  toBeAround(actual, expected, precision = 14) {
    const pass = Math.abs(expected - actual) < Math.pow(10, -precision) / 2;
    if (pass) {
      return {
        message: () => `expected ${actual} not to be around ${expected}`,
        pass: true
      };
    } else {
      return {
        message: () => `expected ${actual} to be around ${expected}`,
        pass: false
      };
    }
  }
});

describe("cdflib_wasm", () => {
  const cdflib = new CdfLibWrapper(true);

  describe("cdftnc", () => {
    const t = 2.10092204024096;
    const df = 18;
    const nc = 1.42445665344;
    const p = 0.729386557105441;

    test("cdftnc_1", () => {
      const expectedP = cdflib.cdftnc_1(df, nc, t);
      expect(expectedP).toBe(p);
    });
  });

  describe("cdftnc", () => {
    const df = 18;
    const t = -2.10092204024096;
    const p = 0.025;

    test("cdft_1", () => {
      const expectedP = cdflib.cdft_1(df, t);
      expect(expectedP).toBeAround(p);
    });

    test("cdft_2", () => {
      const expectedT = cdflib.cdft_2(df, p);
      expect(expectedT).toBe(t);
    });
  });
});
