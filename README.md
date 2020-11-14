# cdflib_wasm

cdflib_wasm is a WebAssembly packaging of the [cdflib library](http://www.netlib.org/random/)
as it appears in the [presto](https://github.com/scottransom/presto/blob/master/src/dcdflib.c) project.

> This library contains routines to compute cumulative distribution
> functions, inverses, and parameters of the distribution for the
> following set of statistical distributions:

    (1) Beta
    (2) Binomial
    (3) Chi-square
    (4) Noncentral Chi-square
    (5) F
    (6) Noncentral F
    (7) Gamma
    (8) Negative Binomial
    (9) Normal
    (10) Poisson
    (11) Student's t
    (12) Noncentral Student's t

> Given values of all but one parameter of a distribution, the other is
> computed. These calculations are done with C pointers to Doubles.

_<sub>http://www.netlib.org/random/ dcdflib.c README file</sub>_

## Table of Content

| Functions           | Documentation                                                      |
| ------------------- | ------------------------------------------------------------------ |
| [`cdfbet`](#cdfbet) | Calculates parameters of the beta distribution.                    |
| [`cdfbin`](#cdfbin) | Calculates parameters of the binomial distribution.                |
| [`cdfchi`](#cdfchi) | Calculates parameters of the chi-square distribution.              |
| [`cdfchn`](#cdfchn) | Calculates parameters of the non-central chi-square distribution.  |
| [`cdff`](#cdff)     | Calculates parameters of the F distribution.                       |
| [`cdffnc`](#cdffnc) | Calculates parameters of the non-central F distribution.           |
| [`cdfgam`](#cdfgam) | Calculates parameters of the gamma distribution.                   |
| [`cdfnbn`](#cdfnbn) | Calculates parameters of the negative binomial distribution.       |
| [`cdfnor`](#cdfnor) | Calculates parameters of the normal distribution.                  |
| [`cdfpoi`](#cdfpoi) | Calculates parameters of the Poisson distribution.                 |
| [`cdft`](#cdft)     | Calculates parameters of the student's t distribution.             |
| [`cdftnc`](#cdftnc) | Calculates parameters of the non-central student's t distribution. |

## Documentation

### cdfbet

Calculates any one parameter of the beta distribution given values for the others.

    P <--> The integral from 0 to X of the chi-square
            distribution.
            Input range: [0, 1].

    X <--> Upper limit of integration of beta density.
        Input range: [0, 1].
        Search range: [0, 1]

    A <--> The first parameter of the beta density.
        Input range: (0, +infinity).
        Search range: [1D-100, 1D100]

    B <--> The second parameter of the beta density.
        Input range: (0, +infinity).
        Search range: [1D-100, 1D100]

#### cdfbet_1(double x, double a, double b): double

`cdfbet_1` Calculates P from X, A and B

```js
const p = cdflib.cdfbet_1(x, a, b);
```

#### cdfbet_2(double p, double a, double b): double

`cdfbet_2` Calculate X from P, A and B

```js
const x = cdflib.cdfbet_2(p, a, b);
```

#### cdfbet_3(double p, double b, double x): double

`cdfbet_3` Calculate A from P, X and B

```js
const a = cdflib.cdfbet_3(p, b, x);
```

#### cdfbet_4(double a, double p, double x): double

`cdfbet_4` Calculate B from P, X and A

```js
const b = cdflib.cdfbet_4(a, p, x);
```

### cdfbin

Calculates any one parameter of the binomial distribution given values for the others.

    P <--> The cumulation from 0 to S of the binomial distribution.
        (Probablility of S or fewer successes in XN trials each
        with probability of success PR.)
        Input range: [0, 1].

    S <--> The number of successes observed.
        Input range: [0, XN]
        Search range: [0, XN]

    XN  <--> The number of binomial trials.
            Input range: (0, +infinity).
            Search range: [1E-100, 1E100]

    PR  <--> The probability of success in each binomial trial.
            Input range: [0, 1].
            Search range: [0, 1]

#### cdfbin_1(double s, double xn, double pr): double

`cdfbin_1` Calculate P from S, XN, PR

```js
const p = cdflib.cdfbin_1(s, xn, pr);
```

#### cdfbin_2(double p, double xn, double pr): double

`cdfbin_2` Calculate S from P, XN, PR

```js
const s = cdflib.cdfbin_2(p, xn, pr);
```

#### cdfbin_3(double p, double s, double pr): double

`cdfbin_3` Calculate XN from P, S, PR

```js
const xn = cdflib.cdfbin_3(p, s, pr);
```

#### cdfbin_4(double p, double s, double xn): double

`cdfbin_4` Calculate PR from P, S and XN

```js
const pr = cdflib.cdfbin_4(p, s, xn);
```

### cdfchi

Calculates any one parameter of the chi-squared distribution given values for the others.

    P <--> The integral from 0 to X of the chi-square
        distribution.
        Input range: [0, 1].

    X <--> Upper limit of integration of the non-central
        chi-square distribution.
        Input range: [0, +infinity).
        Search range: [0, 1E100]

    DF <--> Degrees of freedom of the
            chi-square distribution.
            Input range: (0, +infinity).
            Search range: [ 1E-100, 1E100]

#### cdfchi_1(double x, double df): double

`cdfchi_1` Calculate P from X and DF

```js
const p = cdflib.cdfchi_1(x, df);
```

#### cdfchi_2(double p, double df): double

`cdfchi_2` Calculate X from P and DF

```js
const x = cdflib.cdfchi_2(p, df);
```

#### cdfchi_3(double p, double x): double

`cdfchi_3` Calculate DF from P and X

```js
const df = cdflib.cdfchi_3(p, x);
```

### cdfchn

Calculates any one parameter of the non-central chi-squared distribution given values for the others.

    P <--> The integral from 0 to X of the non-central chi-square
        distribution.
        Input range: [0, 1-1E-16).

    X <--> Upper limit of integration of the non-central
        chi-square distribution.
        Input range: [0, +infinity).
        Search range: [0, 1E100]

    DF <--> Degrees of freedom of the non-central
            chi-square distribution.
            Input range: (0, +infinity).
            Search range: [ 1E-100, 1E100]

    NC <--> Non-centrality parameter of the non-central
            chi-square distribution.
            Input range: [0, +infinity).
            Search range: [0, 1E4]

**Warning**
The computation time required for this routine is proportional to the noncentrality parameter (NC). Very large values of this parameter can consume immense computer resources. This is why the search range is bounded by 10,000.

#### cdfchn_1(double x, double df, double nc): double

`cdfchn_1` Calculate P from X and DF

```js
const p = cdflib.cdfchn_1(x, df, nc);
```

#### cdfchn_2(double p, double df, double nc): double

`cdfchn_2` Calculate X from P, DF and NC

```js
const x = cdflib.cdfchn_2(p, df, nc);
```

#### cdfchn_3(double x, double p, double nc): double

`cdfchn_3` Calculate DF from P, X and NC

```js
const df = cdflib.cdfchn_3(x, p, nc);
```

#### cdfchn_4(double x, double df, double p): double

`cdfchn_4` Calculate NC from P, X and DF

```js
const pnonc = cdflib.cdfchn_4(x, df, p);
```

### cdff

Calculates any one parameter of the F distribution given values for the others.

    P <--> The integral from 0 to F of the f-density.
            Input range: [0, 1].

    F <--> Upper limit of integration of the f-density.
            Input range: [0, +infinity).
            Search range: [0, 1E100]

    DFN < --> Degrees of freedom of the numerator sum of squares.
            Input range: (0, +infinity).
            Search range: [ 1E-100, 1E100]

    DFD < --> Degrees of freedom of the denominator sum of squares.
            Input range: (0, +infinity).
            Search range: [ 1E-100, 1E100]

**Warning**
The value of the cumulative F distribution is not necessarily
monotone in either degrees of freedom. There thus may be two
values that provide a given CDF value. This routine assumes
monotonicity and will find an arbitrary one of the two values.

#### cdff_1(double dfn, double dfd, double f): double

`cdff_1` Calculate P from F, DFN and DFD

```js
const p = cdflib.cdff_1(dfc, dfd, f);
```

#### cdff_2(double dfn, double dfd, double p): double

`cdff_2` Calculate F from P, DFN and DFD

```js
const f = cdflib.cdff_2(dfn, dfd, p);
```

#### cdff_3(double p, double dfd, double f): double

`cdff_3` Calculate DFN from P, F and DFD

```js
const dfn = cdflib.cdff_3(p, dfd, f);
```

#### cdff_4(double dfn, double p, double f): double

`cdff_4` Calculate DFD from P, F and DFN

```js
const dfd = cdflib.cdff_4(dfn, p, f);
```

### cdffnc

Calculates any one parameter of the Non-central F distribution given values for the others.

    P <--> The integral from 0 to F of the non-central f-density.
            Input range: [0, 1-1E-16).

    F <--> Upper limit of integration of the non-central f-density.
            Input range: [0, +infinity).
            Search range: [0, 1E100]

    DFN < --> Degrees of freedom of the numerator sum of squares.
            Input range: (0, +infinity).
            Search range: [ 1E-100, 1E100]

    DFD < --> Degrees of freedom of the denominator sum of squares.
            Must be in range: (0, +infinity).
            Input range: (0, +infinity).
            Search range: [ 1E-100, 1E100]

    NC <-> The non-centrality parameter
            Input range: [0, infinity)
            Search range: [0, 1E4]

**Warning**

The computation time required for this routine is proportional
to the noncentrality parameter (PNONC). Very large values of
this parameter can consume immense computer resources. This is
why the search range is bounded by 10,000.

**Warning**

The value of the cumulative noncentral F distribution is not
necessarily monotone in either degrees of freedom. There thus
may be two values that provide a given CDF value. This routine
assumes monotonicity and will find an arbitrary one of the two
values.

#### cdffnc_1(double dfn, double dfd, double nc, double f): double

`cdffnc_1` Calculate P from F, DFN, DFD and NC

```js
const p = cdflib.cdffnc_1(dfc, dfd, nc, f);
```

#### cdffnc_2(double dfn, double dfd, double nc, double p): double

`cdffnc_2` Calculate F from P, DFN, DFD and NC

```js
const f = cdflib.cdffnc_2(dfn, dfd, nc, p);
```

#### cdffnc_3(double p, double dfd, double nc, double f): double

`cdffnc_3` Calculate DFN from P, F, DFD and NC

```js
const dfn = cdflib.cdffnc_3(p, dfd, nc, f);
```

#### cdffnc_4(double dfn, double p, double nc, double f): double

`cdffnc_4` Calculate DFD from P, F, DFN and NC

```js
const dfd = cdflib.cdffnc_4(dfn, p, nc, f);
```

#### cdffnc_5(double dfn, double dfd, double p, double f): double

`cdffnc_5` Calculate NC from P, F, DFN and DFD

```js
const pnonc = cdflib.cdffnc_5(dfn, dfd, p, f);
```

### cdfgam

Calculates any one parameter of the gamma
distribution given values for the others.

    P <--> The integral from 0 to X of the gamma density.
        Input range: [0, 1].

    X <--> The upper limit of integration of the gamma density.
        Input range: [0, +infinity).
        Search range: [0, 1E100]

    SHAPE <--> The shape parameter of the gamma density.
            Input range: (0, +infinity).
            Search range: [1E-100, 1E100]

    SCALE <--> The scale parameter of the gamma density.
            Input range: (0, +infinity).
            Search range: (1E-100, 1E100]

#### cdfgam_1(double scale, double shape, double x): double

`cdfgam_1` Calculate P from X, SHAPE and SCALE

```js
const p = cdflib.cdfgam_1(scale, shape, x);
```

#### cdfgam_2(double scale, double shape, double p): double

`cdfgam_2` Calculate X from P, SHAPE and SCALE

```js
const x = cdflib.cdfgam_2(scale, shape, p);
```

#### cdfgam_3(double scale, double p, double x): double

`cdfgam_3` Calculate SHAPE from P, X and SCALE

```js
const shape = cdflib.cdfgam_3(scale, p, x);
```

#### cdfgam_4(double p, double shape, double x): double

`cdfgam_4` Calculate SCALE from P, X and SHAPE

```js
const scale = cdflib.cdfgam_4(p, shape, x);
```

### cdfnbn

Calculates any one parameter of the negative binomial
distribution given values for the others.

The cumulative negative binomial distribution returns the
probability that there will be F or fewer failures before the
XNth success in binomial trials each of which has probability of
success PR.

The individual term of the negative binomial is the probability of
S failures before XN successes and is
`Choose(S, XN+S-1) * PR^(XN) * (1-PR)^S`

    P <--> The cumulation from 0 to S of the  negative
        binomial distribution.
        Input range: [0, 1].

    S <--> The upper limit of cumulation of the binomial distribution.
        There are F or fewer failures before the XNth success.
        Input range: [0, +infinity).
        Search range: [0, 1E100]

    XN  <--> The number of successes.
            Input range: [0, +infinity).
            Search range: [0, 1E100]

    PR  <--> The probability of success in each binomial trial.
            Input range: [0, 1].
            Search range: [0, 1].

#### cdfnbn_1(double s, double xn, double pr): double

`cdfnbn_1` Calculate P from S, XN, PR

```js
const p = cdflib.cdfnbn_1(s, xn, pr);
```

#### cdfnbn_2(double p, double xn, double pr): double

`cdfnbn_2` Calculate S from P, XN, PR

```js
const s = cdflib.cdfnbn_2(p, xn, pr);
```

#### cdfnbn_3(double s, double p, double pr): double

`cdfnbn_3` Calculate XN from P, S, PR

```js
const xn = cdflib.cdfnbn_3(s, p, pr);
```

#### cdfnbn_4(double s, double p, double xn): double

`cdfnbn_4` Calculate PR from P, S and XN

```js
const pr = cdflib.cdfnbn_4(s, p, xn);
```

### cdfnor

Calculates any one parameter of the normal distribution given values for the others.

    P <--> The integral from -infinity to X of the normal density.
        Input range: (0, 1].

    X < --> Upper limit of integration of the normal-density.
            Input range: ( -infinity, +infinity)

    MEAN <--> The mean of the normal density.
            Input range: (-infinity, +infinity)

    STD <--> Standard Deviation of the normal density.
            Input range: (0, +infinity).

**Note**
The normal density is proportional to
`exp( - 0.5 * (( X - MEAN)/STD)**2)`

#### cdfnor_1(double mean, double std, double x): double

`cdfnor_1` Calculate P from X, MEAN and STD

```js
const p = cdflib.cdfnor_1(mean, std, x);
```

#### cdfnor_2(double mean, double p, double std): double

`cdfnor_2` Calculate X from P, MEAN and STD

```js
const x = cdflib.cdfnor_2(mean, p, std);
```

#### cdfnor_3(double p, double std, double x): double

`cdfnor_3` Calculate MEAN from P, X and STD

```js
const mean = cdflib.cdfnor_3(p, std, x);
```

#### cdfnor_4(double mean, double p, double x): double

`cdfnor_4` Calculate STD from P, X and MEAN

```js
const sd = cdflib.cdfnor_4(mean, p, x);
```

### cdfpoi

Calculates any one parameter of the Poisson distribution given values for the others.

    P <--> The cumulation from 0 to S of the poisson density.
            Input range: [0, 1].

    S <--> Upper limit of cumulation of the Poisson.
            Input range: [0, +infinity).
            Search range: [0, 1E100]

    XLAM <--> Mean of the Poisson distribution.
            Input range: [0, +infinity).
            Search range: [0, 1E100]

#### cdfpoi_1(double s, double xlam): double

`cdfpoi_1` Calculate P from S and XLAM

```js
const p = cdflib.cdfpoi_1(s, xlam);
```

#### cdfpoi_2(double p, double xlam): double

`cdfpoi_2` Calculate A from P and XLAM

```js
const a = cdflib.cdfpoi_2(p, xlam);
```

#### cdfpoi_3(double p, double s): double

`cdfpoi_3` Calculate XLAM from P and S

```js
const xlam = cdflib.cdfpoi_3(p, s);
```

### cdft

Calculates any one parameter of the student's t distribution given values for the others.

    P <--> The integral from -infinity to t of the t-density.
            Input range: (0, 1].

    T <--> Upper limit of integration of the t-density.
            Input range: ( -infinity, +infinity).
            Search range: [ -1E100, 1E100 ]

    DF <--> Degrees of freedom of the t-distribution.
            Input range: (0 , +infinity).
            Search range: [1e-100, 1E10]

#### cdft_1(double df, double t): double

`cdft_1` Calculate P from T and DF

```js
const p = cdflib.cdft_1(df, t);
```

#### cdft_2(double df, double p): double

`cdft_2` Calculate T from P and DF

```js
const t = cdflib.cdft_2(p, df);
```

#### cdft_3(double p, double t): double

`cdft_3` Calculate DF from P and T

```js
const df = cdflib.cdft_3(p, t);
```

### cdftnc

Calculates any one parameter of the non-central student's t distribution given values for the others.

    P <--> The integral from -infinity to t of the noncentral t-den
        Input range: (0, 1].

    T <--> Upper limit of integration of the noncentral t-density.
        Input range: ( -infinity, +infinity).
        Search range: [ -1E100, 1E100 ]

    DF <--> Degrees of freedom of the noncentral t-distribution.
            Input range: (0 , +infinity).
            Search range: [1e-100, 1E10]

    NC <--> Noncentrality parameter of the noncentral t-distribution.
                Input range: [-infinity , +infinity).
                Search range: [-1e4, 1E4]

#### cdftnc_1(double df, double nc, double t): double

`cdftnc_1` Calculate P from T, DF, NC

```js
const p = cdflib.cdftnc_1(df, nc, t);
```

#### cdftnc_2(double df, double nc, double p): double

`cdftnc_2` Calculate T from P, DF, NC

```js
const t = cdflib.cdftnc_2(df, nc, p);
```

#### cdftnc_3(double p, double nc, double t): double

`cdftnc_3` Calculate DF from P, NC, T

```js
const df = cdflib.cdftnc_3(p, nc, t);
```

#### cdftnc_4(double df, double p, double t): double

`cdftnc_4` Calculate NC from P, DF, T

```js
const pnonc = cdflib.cdftnc_4(df, p, t);
```

# Credits

- [presto](https://github.com/scottransom/presto) for the cdflib C source
- [node-cephes](https://github.com/nearform/node-cephes) which I heavily borrow the wasm packaging from.
