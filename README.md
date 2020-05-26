# cdflib_wasm

cdflib_wasm is a WebAssembly packaging of the [cdflib library](https://people.sc.fsu.edu/~jburkardt/f_src/cdflib/cdflib.html)
as it appears in the [presto](https://github.com/scottransom/presto/blob/master/src/dcdflib.c) project.

_<sub>Quote from https://people.sc.fsu.edu/~jburkardt/f_src/cdflib/cdflib.html</sub>_

> CDFLIB is a FORTRAN90 library which evaluates the cumulative density function (CDF) associated with common probability distributions, by Barry Brown, James Lovato, Kathy Russell.
>
> CDFLIB includes routines for evaluating the cumulative density functions of a variety of standard probability distributions. An unusual feature of this library is its ability to easily compute any one parameter of the CDF given the others. This means that a single routine can evaluate the CDF given the usual parameters, or determine the value of a parameter that produced a given CDF value.

# Credits

- [presto](https://github.com/scottransom/presto) for the cdflib source
- [node-cephes](https://github.com/nearform/node-cephes) which I heavily borrow the wasm packaging from.
