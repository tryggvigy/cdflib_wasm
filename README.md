# cdflib_wasm

cdflib_wasm is a WebAssembly packaging of the [cdflib library](https://people.sc.fsu.edu/~jburkardt/f_src/cdflib/cdflib.html)
as it appears in the [presto](https://github.com/scottransom/presto/blob/master/src/dcdflib.c) project.

_<sub>Quote from https://people.sc.fsu.edu/~jburkardt/f_src/cdflib/cdflib.html</sub>_

> CDFLIB is a FORTRAN90 library which evaluates the cumulative density function (CDF) associated with common probability distributions, by Barry Brown, James Lovato, Kathy Russell.
>
> CDFLIB includes routines for evaluating the cumulative density functions of a variety of standard probability distributions. An unusual feature of this library is its ability to easily compute any one parameter of the CDF given the others. This means that a single routine can evaluate the CDF given the usual parameters, or determine the value of a parameter that produced a given CDF value.

## Table of Content

| Functions           | Documentation                                       |
| ------------------- | --------------------------------------------------- |
| [`cdfbet`](#cdfbet) | Calculates parameters of the beta distribution.     |
| [`cdfbin`](#cdfbin) | Calculates parameters of the binomial distribution. |

## Documentation

### cdfbet

Calculates any one parameter of the beta distribution given values for the others.

    P <--> The integral from 0 to X of the chi-square
            distribution.
            Input range: [0, 1].

    Q <--> 1-P.
        Input range: [0, 1].
        P + Q = 1.0.

    X <--> Upper limit of integration of beta density.
        Input range: [0,1].
        Search range: [0,1]

    Y <--> 1-X.
        Input range: [0,1].
        Search range: [0,1]
        X + Y = 1.0.

    A <--> The first parameter of the beta density.
        Input range: (0, +infinity).
        Search range: [1D-100,1D100]

    B <--> The second parameter of the beta density.
        Input range: (0, +infinity).
        Search range: [1D-100,1D100]

#### cdflib.cdfbet_1(double x, double a, double b): double

`cdfbet_1` Calculates P and Q from X, Y, A and B

```js
const p = cdflib.cdfbet_1(x, a, b);
```

#### cdflib.cdfbet_2(double p, double a, double b): double

`cdfbet_2` Calculate X and Y from P,Q,A and B

```js
const x = cdflib.cdfbet_2(p, a, b);
```

#### cdflib.cdfbet_3(double p, double b, double x): double

`cdfbet_3` Calculate A from P,Q,X,Y and B

```js
const a = cdflib.cdfbet_3(p, b, x);
```

#### cdflib.cdfbet_4(double a, double p, double x): double

`cdfbet_4` Calculate B from P,Q,X,Y and A

```js
const b = cdflib.cdfbet_4(a, p, x);
```

### cdfbin

Calculates any one parameter of the binomial distribution given values for the others.

    P <--> The cumulation from 0 to S of the binomial distribution.
        (Probablility of S or fewer successes in XN trials each
        with probability of success PR.)
        Input range: [0,1].

    Q <--> 1-P.
        Input range: [0, 1].
        P + Q = 1.0.

    S <--> The number of successes observed.
        Input range: [0, XN]
        Search range: [0, XN]

    XN  <--> The number of binomial trials.
            Input range: (0, +infinity).
            Search range: [1E-100, 1E100]

    PR  <--> The probability of success in each binomial trial.
            Input range: [0,1].
            Search range: [0,1]

    OMPR  <--> 1-PR
            Input range: [0,1].
            Search range: [0,1]
            PR + OMPR = 1.0

#### cdflib.cdfbin_1(double s, double xn, double pr): double

`cdfbin_1` Calculate P and Q from S,XN,PR and OMPR

```js
const p = cdflib.cdfbin_1(s, xn, pr);
```

#### cdflib.cdfbin_2(double p, double xn, double pr): double

`cdfbin_2` Calculate S from P,Q,XN,PR and OMPR

```js
const s = cdflib.cdfbin_2(p, xn, pr);
```

#### cdflib.cdfbin_3(double p, double s, double pr): double

`cdfbin_3` Calculate XN from P,Q,S,PR and OMPR

```js
const xn = cdflib.cdfbin_3(p, s, pr);
```

#### cdflib.cdfbin_4(double p, double s, double xn): double

`cdfbin_4` Calculate PR and OMPR from P,Q,S and XN

```js
const pr = cdflib.cdfbin_4(p, s, xn);
```

# Credits

- [presto](https://github.com/scottransom/presto) for the cdflib source
- [node-cephes](https://github.com/nearform/node-cephes) which I heavily borrow the wasm packaging from.
