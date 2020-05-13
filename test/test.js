const CdfLibWrapper = require("../cdflibNode");
const CdfLibStandaloneWrapper = require("../cdflibStandalone");

expect.extend({
  toBeAround(actual, expected, precision) {
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

  test("algdiv", () => {
    const a = 1;
    const b = 2;
    expect(cdflib.algdiv(a, b)).toBe(-0.6931474509228539);
  });

  test("alngam", () => {
    const x = 7;
    expect(cdflib.alngam(x)).toBe(6.579251212010101);
  });

  test("alnrel", () => {
    const a = 1;
    expect(cdflib.alnrel(a)).toBe(0.6931471805599453);
  });

  test("apser", () => {
    const a = 0.00000001;
    const b = 0.001;
    const x = 0.01;
    const eps = 0.01;
    expect(cdflib.apser(a, b, x, eps)).toBe(0.000010045934865278717);
  });

  test("basym", () => {
    const a = 16;
    const b = 17;
    const lambda = 0.01;
    const eps = 0.01;
    expect(cdflib.basym(a, b, lambda, eps)).toBe(0.5000170778806329);
  });

  describe("cdft", () => {
    const df = 18;
    const t = -2.10092204024096;
    const p = 0.025;

    test("cdft_1", () => {
      expect(cdflib.cdft_1(df, t)).toBeAround(p, 14);
    });

    test("cdft_2", () => {
      expect(cdflib.cdft_2(df, p)).toBe(t);
    });

    test("cdft_3", () => {
      expect(cdflib.cdft_3(p, t)).toBeAround(df, 7);
    });
  });

  describe("cdftnc", () => {
    const t = 2.10092204024096;
    const df = 18;
    const nc = 1.42445665344;
    const p = 0.729386557105441;

    test("cdftnc_1", () => {
      expect(cdflib.cdftnc_1(df, nc, t)).toBe(p);
    });

    test("cdftnc_2", () => {
      expect(cdflib.cdftnc_2(df, nc, p)).toBeAround(t, 12);
    });

    test("cdftnc_3", () => {
      expect(cdflib.cdftnc_3(p, nc, t)).toBeAround(df, 8);
    });

    test("cdftnc_4", () => {
      expect(cdflib.cdftnc_4(df, p, t)).toBeAround(nc, 13);
    });
  });

  describe("standalone version", () => {
    test("works", () => {
      const cdflibStandalone = new CdfLibStandaloneWrapper(true);
      expect(cdflibStandalone.cdft_1(18, -2.10092204024096)).toBeAround(
        0.025,
        14
      );
    });
  });
});
