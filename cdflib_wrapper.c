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

double cdflib_bfrac(double a, double b, double x, double y, double lambda, double eps) {
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
  int which=3;
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
  int which=1;
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
