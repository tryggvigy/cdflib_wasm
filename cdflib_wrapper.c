#include "cdflib.h"

double cdflib_algdiv(double a, double b) {
  return algdiv(&a, &b);
}

double cdflib_alngam(double x) {
  return alngam(&x);
}

double cdflib_alnrel(double a) {
  return alnrel(&a);
}

double cdflib_apser(double a, double b, double x, double eps) {
  return apser(&a, &b, &x, &eps);
}

double cdflib_basym(double a, double b, double lambda, double eps) {
  return basym(&a, &b, &lambda, &eps);
}

double cdflib_bcorr(double a0, double b0) {
  return bcorr(&a0, &b0);
}

double cdflib_betaln(double a0, double b0) {
  return betaln(&a0, &b0);
}

double cdflib_bfrac(double a, double b, double x, double y, double eps) {
  double lambda = (a+b)*y-b;
  return bfrac(&a, &b, &x, &y, &lambda, &eps);
}

double cdflib_bgrat(double a, double b, double x, double y, double eps) {
  double w=0;
  int ierr=10;
  bgrat(&a, &b, &x, &y, &w, &eps, &ierr);
  return w;
}

double cdflib_bpser(double a, double b, double x, double eps) {
  return bpser(&a, &b, &x, &eps);
}

double cdflib_bratio(double a, double b, double x) {
  double y = 1-x;
  double w=0, w1=0;
  int ierr=10;
  bratio(&a, &b, &x, &y, &w, &w1, &ierr);
  return w;
}

double cdflib_brcmp1(int mu, double a, double b, double x, double y) {
  return brcmp1(&mu, &a, &b, &x, &y);
}

double cdflib_brcomp(double a, double b, double x, double y) {
  return brcomp(&a, &b, &x, &y);
}

double cdflib_bup(double a, double b, double x, double y, int n, double eps) {
  return bup(&a, &b, &x, &y, &n, &eps);
}

double cdflib_cdfbet_1(double x, double a, double b) {
  int which=1;
  double y=1.0-x, q=0, p=0, bound=0;
  int status=10;
  cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
  return p;
}

double cdflib_cdfbet_2(double p, double a, double b) {
  int which=2;
  double q=1.0-p, x=0, y=0, bound=0;
  int status=10;
  cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
  return x;
}

double cdflib_cdfbet_3(double p, double b, double x) {
  int which=3;
  double q=1.0-p, y=1.0-x, a=0, bound=0;
  int status=10;
  cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
  return a;
}

double cdflib_cdfbet_4(double a, double p, double x) {
  int which=4;
  double q=1.0-p, y=1.0-x, b=0, bound=0;
  int status=10;
  cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
  return b;
}

double cdflib_cdfbin_1(double s, double xn, double pr) {
  int which=1;
  double ompr=1.0-pr, q=0, p=0, bound=0;
  int status=10;
  cdfbin(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return p;
}

double cdflib_cdfbin_2(double p, double xn, double pr) {
  int which=2;
  double q=1.0-p, ompr=1.0-pr, s=0, bound=0;
  int status=10;
  cdfbin(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return s;
}

double cdflib_cdfbin_3(double p, double s, double pr) {
  int which=3;
  double q=1.0-p, ompr=1.0-pr, xn=0, bound=0;
  int status=10;
  cdfbin(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return xn;
}

double cdflib_cdfbin_4(double p, double s, double xn) {
  int which=4;
  double q=1.0-p, ompr=0, pr=0, bound=0;
  int status=10;
  cdfbin(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return pr;
}

double cdflib_cdfchi_1(double x, double df) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfchi(&which, &p, &q, &x, &df, &status, &bound);
  return p;
}

double cdflib_cdfchi_2(double p, double df) {
  int which=2;
  double q=1.0-p, x=0, bound=0;
  int status=10;
  cdfchi(&which, &p, &q, &x, &df, &status, &bound);
  return x;
}

double cdflib_cdfchi_3(double p, double x) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdfchi(&which, &p, &q, &x, &df, &status, &bound);
  return df;
}

double cdflib_cdfchn_1(double x, double df, double nc) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfchn(&which, &p, &q, &x, &df, &nc, &status, &bound);
  return p;
}

double cdflib_cdfchn_2(double p, double df, double nc) {
  int which=2;
  double q=1.0-p, x=0, bound=0;
  int status=10;
  cdfchn(&which, &p, &q, &x, &df, &nc, &status, &bound);
  return x;
}

double cdflib_cdfchn_3(double x, double p, double nc) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdfchn(&which, &p, &q, &x, &df, &nc, &status, &bound);
  return df;
}

double cdflib_cdfchn_4(double x, double df, double p) {
  int which=4;
  double q=1.0-p, nc=0, bound=0;
  int status=10;
  cdfchn(&which, &p, &q, &x, &df, &nc, &status, &bound);
  return nc;
}

double cdflib_cdff_1(double dfn, double dfd, double f) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdff(&which, &p, &q, &f, &dfn, &dfd, &status, &bound);
  return p;
}

double cdflib_cdff_2(double dfn, double dfd, double p) {
  int which=2;
  double q=1.0-p, f=0, bound=0;
  int status=10;
  cdff(&which, &p, &q, &f, &dfn, &dfd, &status, &bound);
  return f;
}

double cdflib_cdff_3(double p, double dfd, double f) {
  int which=3;
  double q=1.0-p, dfn=0, bound=0;
  int status=10;
  cdff(&which, &p, &q, &f, &dfn, &dfd, &status, &bound);
  return dfn;
}

double cdflib_cdff_4(double dfn, double p, double f) {
  int which=4;
  double q=1.0-p, dfd=0, bound=0;
  int status=10;
  cdff(&which, &p, &q, &f, &dfn, &dfd, &status, &bound);
  return dfd;
}

double cdflib_cdffnc_1(double dfn, double dfd, double nc, double f) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return p;
}

double cdflib_cdffnc_2(double dfn, double dfd, double nc, double p) {
  int which=1;
  double q=1.0-p, f=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return f;
}

double cdflib_cdffnc_3(double p, double dfd, double nc, double f) {
  int which=3;
  double q=1.0-p, dfn=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return dfn;
}

double cdflib_cdffnc_4(double dfn, double p, double nc, double f) {
  int which=4;
  double q=1.0-p, dfd=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return dfd;
}

double cdflib_cdffnc_5(double dfn, double dfd, double p, double f) {
  int which=5;
  double q=1.0-p, nc=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return nc;
}

double cdflib_cdfgam_1(double scale, double shape, double x) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
  return p;
}

double cdflib_cdfgam_2(double scale, double shape, double p) {
  int which=2;
  double q=1.0-p, x=0, bound=0;
  int status=10;
  cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
  return x;
}

double cdflib_cdfgam_3(double scale, double p, double x) {
  int which=3;
  double q=1.0-p, shape=0, bound=0;
  int status=10;
  cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
  return shape;
}

double cdflib_cdfgam_4(double p, double shape, double x) {
  int which=4;
  double q=1.0-p, scale=0, bound=0;
  int status=10;
  cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
  return scale;
}

double cdflib_cdfnbn_1(double s, double xn, double pr) {
  int which=1;
  double q=0, p=0, ompr=1.0-pr, bound=0;
  int status=10;
  cdfnbn(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return p;
}

double cdflib_cdfnbn_2(double p, double xn, double pr) {
  int which=2;
  double q=1.0-p, s=0, ompr=1.0-pr, bound=0;
  int status=10;
  cdfnbn(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return s;
}

double cdflib_cdfnbn_3(double s, double p, double pr) {
  int which=3;
  double q=1.0-p, xn=0, ompr=1.0-pr, bound=0;
  int status=10;
  cdfnbn(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return xn;
}

double cdflib_cdfnbn_4(double s, double p, double xn) {
  int which=4;
  double q=1.0-p, pr=0, ompr=0, bound=0;
  int status=10;
  cdfnbn(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return pr;
}

double cdflib_cdfnor_1(double mean, double std, double x) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfnor(&which, &p, &q, &x, &mean, &std, &status, &bound);
  return p;
}

double cdflib_cdfnor_2(double mean, double p, double std) {
  int which=2;
  double q=1.0-p, x=0, bound=0;
  int status=10;
  cdfnor(&which, &p, &q, &x, &mean, &std, &status, &bound);
  return x;
}

double cdflib_cdfnor_3(double p, double std, double x) {
  int which=3;
  double q=1.0-p, mean=0, bound=0;
  int status=10;
  cdfnor(&which, &p, &q, &x, &mean, &std, &status, &bound);
  return mean;
}

double cdflib_cdfnor_4(double mean, double p, double x) {
  int which=4;
  double q=1.0-p, std=0, bound=0;
  int status=10;
  cdfnor(&which, &p, &q, &x, &mean, &std, &status, &bound);
  return std;
}

double cdflib_cdfpoi_1(double s, double xlam) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfpoi(&which, &p, &q, &s, &xlam, &status, &bound);
  return p;
}

double cdflib_cdfpoi_2(double p, double xlam) {
  int which=2;
  double q=1.0-p, s=0, bound=0;
  int status=10;
  cdfpoi(&which, &p, &q, &s, &xlam, &status, &bound);
  return s;
}

double cdflib_cdfpoi_3(double p, double s) {
  int which=3;
  double q=1.0-p, xlam=0, bound=0;
  int status=10;
  cdfpoi(&which, &p, &q, &s, &xlam, &status, &bound);
  return xlam;
}

double cdflib_cdft_1(double df, double t) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return p;
}

double cdflib_cdft_2(double df, double p) {
  int which=2;
  double q=1.0-p, t=0, bound=0;
  int status=10;
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return t;
}

double cdflib_cdft_3(double p, double t) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return df;
}

double cdflib_cdftnc_1(double df, double nc, double t) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return p;
}

double cdflib_cdftnc_2(double df, double nc, double p) {
  int which=2;
  double q=1.0-p, t=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return t;
}

double cdflib_cdftnc_3(double p, double nc, double t) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return df;
}

double cdflib_cdftnc_4(double df, double p, double t) {
  int which=4;
  double q=1.0-p, nc=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return nc;
}

// TODO
void cdflib_cumbet(double x, double y, double a, double b, double cum, double ccum) {
  cumbet(&x, &y, &a, &b, &cum, &ccum);
}

// TODO
void cdflib_cumbin(double s, double xn, double pr, double ompr, double cum, double ccum) {
  cumbin(&s, &xn, &pr, &ompr, &cum, &ccum);
}

// TODO
void cdflib_cumchi(double x, double df, double cum, double ccum) {
  cumchi(&x, &df, &cum, &ccum);
}

// TODO
void cdflib_cumchn(double x, double df, double pnonc, double cum, double ccum) {
  cumchn(&x, &df, &pnonc, &cum, &ccum);
}

// TODO
void cdflib_cumf(double f, double dfn, double dfd, double cum, double ccum) {
  cumf(&f, &dfn, &dfd, &cum, &ccum);
}

// TODO
void cdflib_cumfnc(double f, double dfn, double dfd, double pnonc,
                   double cum, double ccum) {
  cumfnc(&f, &dfn, &dfd, &pnonc, &cum, &ccum);
}

// TODO
void cdflib_cumgam(double x, double a, double cum, double ccum) {
  cumgam(&x, &a, &cum, &ccum);
}

// TODO
void cdflib_cumnbn(double s, double xn, double pr, double ompr,
                   double cum, double ccum) {
  cumnbn(&s, &xn, &pr, &ompr, &cum, &ccum);
}

// TODO
void cdflib_cumnor(double arg, double result, double ccum) {
  cumnor(&arg, &result, &ccum);
}

// TODO
void cdflib_cumpoi(double s, double xlam, double cum, double ccum) {
  cumpoi(&s, &xlam, &cum, &ccum);
}

// TODO
void cdflib_cumt(double t, double df, double cum, double ccum) {
  cumt(&t, &df, &cum, &ccum);
}

// TODO
void cdflib_cumtnc(double t, double df, double nc, double cum, double ccum) {
  cumtnc(&t, &df, &nc, &cum, &ccum);
}

double cdflib_devlpl(double a[], int n, double x) {
  return devlpl(a, &n, &x);
}

double cdflib_dinvnr(double p, double q) {
  return dinvnr(&p, &q);
}

// TODO
void cdflib_dinvr(int status, double x, double fx,
                  unsigned long qleft, unsigned long qhi) {
  dinvr(&status, &x, &fx, &qleft, &qhi);
}

// TODO
void cdflib_dstinv(double zsmall, double zbig, double zabsst,
                   double zrelst, double zstpmu, double zabsto, double zrelto) {
  dstinv(&zsmall, &zbig, &zabsst, &zrelst, &zstpmu, &zabsto, &zrelto);
}

double cdflib_dt1(double p, double df) {
  double q=1.0-p;
  return dt1(&p, &q, &df);
}

// TODO
void cdflib_dzror(int status, double x, double fx, double xlo,
           double xhi, unsigned long qleft, unsigned long qhi) {
  dzror(&status, &x, &fx, &xlo, &xhi, &qleft, &qhi);
}

// TODO
void cdflib_dstzr(double zxlo, double zxhi, double zabstl, double zreltl) {
  dstzr(&zxlo, &zxhi, &zabstl, &zreltl);
}

double cdflib_erf1(double x) {
  return erf1(&x);
}

double cdflib_erfc1(int ind, double x) {
  return erfc1(&ind, &x);
}

double cdflib_esum(int mu, double x) {
  return esum(&mu, &x);
}

double cdflib_exparg(int l) {
  return exparg(&l);
}

double cdflib_fpser(double a, double b, double x, double eps) {
  return fpser(&a, &b, &x, &eps);
}

double cdflib_gam1(double a) {
  return gam1(&a);
}

// TODO
void cdflib_gaminv(double a, double x, double x0, double p, double q, int ierr) {
  gaminv(&a, &x, &x0, &p, &q, &ierr);
}

double cdflib_gamln(double a) {
  return gamln(&a);
}

double cdflib_gamln1(double a) {
  return gamln1(&a);
}

double cdflib_Xgamm(double a) {
  return Xgamm(&a);
}

// TODO
void cdflib_gratio(double a, double x, double ans, double qans, int ind) {
  gratio(&a, &x, &ans, &qans, &ind);
}

double cdflib_gsumln(double a, double b) {
  return gsumln(&a, &b);
}

double cdflib_psi(double xx) {
  return psi(&xx);
}

double cdflib_rcomp(double a, double x) {
  return rcomp(&a, &x);
}

double cdflib_rexp(double x) {
  return rexp(&x);
}

double cdflib_rlog(double x) {
  return rlog(&x);
}

double cdflib_rlog1(double x) {
  return rlog1(&x);
}

double cdflib_spmpar(int i) {
  return spmpar(&i);
}

double cdflib_stvaln(double p) {
  return stvaln(&p);
}
