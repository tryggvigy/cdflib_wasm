# cdflib_wasm

cdflib_wasm is a WebAssembly packaging of the [cdflib library](https://people.sc.fsu.edu/~jburkardt/f_src/cdflib/cdflib.html)
as it appears in the [presto](https://github.com/scottransom/presto/blob/master/src/dcdflib.c) project.

_<sub>Quote from https://people.sc.fsu.edu/~jburkardt/f_src/cdflib/cdflib.html</sub>_

> CDFLIB is a FORTRAN90 library which evaluates the cumulative density function (CDF) associated with common probability distributions, by Barry Brown, James Lovato, Kathy Russell.
>
> CDFLIB includes routines for evaluating the cumulative density functions of a variety of standard probability distributions. An unusual feature of this library is its ability to easily compute any one parameter of the CDF given the others. This means that a single routine can evaluate the CDF given the usual parameters, or determine the value of a parameter that produced a given CDF value.

## Table of Content

| Function   | Documentation |
| ---------- | ------------- |
| `cdfbet_1` | TODO          |

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
const ret = cdflib.cdfbet_1(x, a, b);
```

# Credits

- [presto](https://github.com/scottransom/presto) for the cdflib source
- [node-cephes](https://github.com/nearform/node-cephes) which I heavily borrow the wasm packaging from.
