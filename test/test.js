const CdfLibWrapper = require("../out/cdflibNode");
const CdfLibStandaloneWrapper = require("../out/cdflibStandalone");

expect.extend({
  toBeAround(actual, expected, precision = 6) {
    const pass = Math.abs(expected - actual) < Math.pow(10, -precision) / 2;
    if (pass) {
      return {
        message: () => `expected ${actual} not to be around ${expected}`,
        pass: true,
      };
    } else {
      return {
        message: () => `expected ${actual} to be around ${expected}`,
        pass: false,
      };
    }
  },
});

describe("cdflib_wasm", () => {
  const cdflib = new CdfLibWrapper(true);

  describe("cdfbet", () => {
    const x = 0.5998027288886079;
    const a = 13.2;
    const b = 3;
    const p = 0.025;

    test("cdfbet_1", () => {
      expect(cdflib.cdfbet_1(x, a, b)).toBeAround(p);
      expect(() => cdflib.cdfbet_1(-0.01, a, b)).toThrowError(
        new RangeError(
          'cdflib reports "(C Lang) input parameter 4 is out of range" in cdfbet1'
        )
      );
      expect(() => cdflib.cdfbet_1(1.01, a, b)).toThrowError(
        new RangeError(
          'cdflib reports "(C Lang) input parameter 4 is out of range" in cdfbet1'
        )
      );
    });

    test("cdfbet_2", () => {
      expect(cdflib.cdfbet_2(p, a, b)).toBe(x);
    });

    test("cdfbet_3", () => {
      expect(cdflib.cdfbet_3(p, b, x)).toBeAround(a);
    });

    test("cdfbet_4", () => {
      expect(cdflib.cdfbet_4(a, p, x)).toBeAround(b);
    });
  });

  describe("cdfbin", () => {
    const p = 0.025;
    const s = 300;
    const xn = 819.7188346644044;
    const pr = 0.4;

    test("cdfbin_1", () => {
      expect(cdflib.cdfbin_1(s, xn, pr)).toBeAround(p);
    });

    test("cdfbin_2", () => {
      expect(cdflib.cdfbin_2(p, xn, pr)).toBeAround(s);
    });

    test("cdfbin_3", () => {
      expect(cdflib.cdfbin_3(p, s, pr)).toBeAround(xn);
    });

    test("cdfbin_4", () => {
      expect(cdflib.cdfbin_4(p, s, xn)).toBeAround(pr);
    });
  });

  describe("cdfchi", () => {
    const p = 0.025;
    const x = 8.230746194746484;
    const df = 18;

    test("cdfchi_1", () => {
      expect(cdflib.cdfchi_1(x, df)).toBeAround(p);
    });

    test("cdfchi_2", () => {
      expect(cdflib.cdfchi_2(p, df)).toBeAround(x);
    });

    test("cdfchi_3", () => {
      expect(cdflib.cdfchi_3(p, x)).toBeAround(df);
    });
  });

  describe("cdfchn", () => {
    const x = 9.716905660200746;
    const nc = 3.1;
    const df = 18;
    const p = 0.025;

    test("cdfchn_1", () => {
      expect(cdflib.cdfchn_1(x, df, nc)).toBeAround(p);
    });

    test("cdfchn_2", () => {
      expect(cdflib.cdfchn_2(p, df, nc)).toBe(x);
    });

    test("cdfchn_3", () => {
      expect(cdflib.cdfchn_3(x, p, nc)).toBeAround(df);
    });

    test("cdfchn_4", () => {
      expect(cdflib.cdfchn_4(x, df, p)).toBeAround(nc);
    });
  });

  describe("cdff", () => {
    const f = 10;
    const dfn = 0.023;
    const dfd = 0.02184053257710943;
    const p = 0.5;

    test("cdff_1", () => {
      expect(cdflib.cdff_1(dfn, dfd, f)).toBeAround(p);
    });

    test("cdff_2", () => {
      expect(cdflib.cdff_2(dfn, dfd, p)).toBeAround(f);
    });

    test("cdff_3", () => {
      expect(cdflib.cdff_3(p, dfd, f)).toBeAround(dfn);
    });

    test("cdff_4", () => {
      expect(cdflib.cdff_4(dfn, p, f)).toBeAround(dfd);
    });
  });

  describe("cdffnc", () => {
    const f = 10;
    const dfn = 1;
    const dfd = 2;
    const p = 0.8103163170059843;
    const nc = 1.43;

    test("cdffnc_1", () => {
      expect(cdflib.cdffnc_1(dfn, dfd, nc, f)).toBeAround(p);
    });

    test("cdffnc_2", () => {
      expect(cdflib.cdffnc_2(dfn, dfd, nc, p)).toBeAround(f);
    });

    test("cdffnc_2 errors", () => {
      expect(() => cdflib.cdffnc_2(dfn, dfd, nc, 1 - 1e-15)).toThrowError(
        new RangeError(
          'cdflib reports "Answer appears to be higher than greatest search (1e+100)" in cdffnc2'
        )
      );
    });

    test("cdffnc_3", () => {
      expect(cdflib.cdffnc_3(p, dfd, nc, f)).toBeAround(dfn);
    });

    test("cdffnc_4", () => {
      expect(cdflib.cdffnc_4(dfn, p, nc, f)).toBeAround(dfd);
    });

    test("cdffnc_5", () => {
      expect(cdflib.cdffnc_5(dfn, dfd, p, f)).toBeAround(nc);
    });
  });

  describe("cdfgam", () => {
    const scale = 10;
    const shape = 0.4894039080454661;
    const x = 0.02184053257710943;
    const p = 0.5;

    test("cdfgam_1", () => {
      expect(cdflib.cdfgam_1(scale, shape, x)).toBeAround(p);
    });

    test("cdfgam_2", () => {
      expect(cdflib.cdfgam_2(scale, shape, p)).toBeAround(x);
    });

    test("cdfgam_3", () => {
      expect(cdflib.cdfgam_3(scale, p, x)).toBeAround(shape);
    });

    test("cdfgam_4", () => {
      expect(cdflib.cdfgam_4(p, shape, x)).toBeAround(scale);
    });
  });

  describe("cdfnbn", () => {
    const s = 10;
    const xn = 7;
    const pr = 0.5;
    const p = 0.8338470458984374;

    test("cdfnbn_1", () => {
      expect(cdflib.cdfnbn_1(s, xn, pr)).toBeAround(p);
    });

    test("cdfnbn_2", () => {
      expect(cdflib.cdfnbn_2(p, xn, pr)).toBeAround(s);
    });

    test("cdfnbn_3", () => {
      expect(cdflib.cdfnbn_3(s, p, pr)).toBeAround(xn);
    });

    test("cdfnbn_4", () => {
      expect(cdflib.cdfnbn_4(s, p, xn)).toBeAround(pr);
    });
  });

  describe("cdfnor", () => {
    const mean = 10;
    const std = 1;
    const x = 9;
    const p = 0.15865525393145705;

    test("cdfnor_1", () => {
      expect(cdflib.cdfnor_1(mean, std, x)).toBe(p);
    });

    test("cdfnor_2", () => {
      expect(cdflib.cdfnor_2(mean, p, std)).toBe(x);
    });

    test("cdfnor_3", () => {
      expect(cdflib.cdfnor_3(p, std, x)).toBe(mean);
    });

    test("cdfnor_4", () => {
      expect(cdflib.cdfnor_4(mean, p, x)).toBe(std);
    });
  });

  describe("cdfpoi", () => {
    const s = 11;
    const xlam = 10;
    const p = 0.6967761463031059;

    test("cdfpoi_1", () => {
      expect(cdflib.cdfpoi_1(s, xlam)).toBeAround(p);
    });

    test("cdfpoi_2", () => {
      expect(cdflib.cdfpoi_2(p, xlam)).toBeAround(s);
    });

    test("cdfpoi_3", () => {
      expect(cdflib.cdfpoi_3(p, s)).toBeAround(xlam);
    });
  });

  describe("cdft", () => {
    const df = 18;
    const t = -2.10092204024096;
    const p = 0.025;

    test("cdft_1", () => {
      expect(cdflib.cdft_1(df, t)).toBeAround(p);
    });

    test("cdft_2", () => {
      expect(cdflib.cdft_2(df, p)).toBe(t);
    });

    test("cdft_3", () => {
      expect(cdflib.cdft_3(p, t)).toBeAround(df);
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
      expect(cdflib.cdftnc_2(df, nc, p)).toBeAround(t);
    });

    test("cdftnc_3", () => {
      expect(cdflib.cdftnc_3(p, nc, t)).toBeAround(df);
    });

    test("cdftnc_4", () => {
      expect(cdflib.cdftnc_4(df, p, t)).toBeAround(nc);
    });
  });

  test("standalone version works", () => {
    const cdflibStandalone = new CdfLibStandaloneWrapper(true);
    expect(cdflibStandalone.cdft_1(18, -2.10092204024096)).toBeAround(0.025);
  });

  test("async compilation works", async () => {
    const cdflibAsync = new CdfLibWrapper();
    await cdflibAsync.compiled;
    expect(cdflibAsync.cdft_1(18, -2.10092204024096)).toBeAround(0.025);
  });
});
