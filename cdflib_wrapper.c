#include "cdflib.h"
#include <stdio.h>

/* Used for removing _malloc and _free in the exports.
 * Worth not having to deal with the extra memory mangement
 * (dead functions and pointers) that are never going to be used.
 */
void *__attribute__((noinline)) malloc(unsigned long size) { return (void *)0; }
void __attribute__((noinline)) free(void *ptr) { return; }

// Errors are managed in JavaScript
extern void mtherr(char* name, int status, double bound, double result);


static double get_result(char *name, int status, double bound, double result /*, int return_bound */) {
  if (status != 0) {
    mtherr(name, status, bound, result);
  }
  return result;
}


/**
 * **************************************************
 * CDFLIB - Continuous Distribution Functions Library
 * **************************************************
 */

double cdflib_cdfbet_1(double x, double a, double b) {
  int which=1;
  double y=1.0-x, q=0, p=0, bound=0;
  int status=10;
  cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
  return get_result("cdfbet1", status, bound, p);
}

double cdflib_cdfbet_2(double p, double a, double b) {
  int which=2;
  double q=1.0-p, x=0, y=0, bound=0;
  int status=10;
  cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
  return get_result("cdfbet2", status, bound, x);
}

double cdflib_cdfbet_3(double p, double b, double x) {
  int which=3;
  double q=1.0-p, y=1.0-x, a=0, bound=0;
  int status=10;
  cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
  return get_result("cdfbet3", status, bound, a);
}

double cdflib_cdfbet_4(double a, double p, double x) {
  int which=4;
  double q=1.0-p, y=1.0-x, b=0, bound=0;
  int status=10;
  cdfbet(&which, &p, &q, &x, &y, &a, &b, &status, &bound);
  return get_result("cdfbet4", status, bound, b);
}

double cdflib_cdfbin_1(double s, double xn, double pr) {
  int which=1;
  double ompr=1.0-pr, q=0, p=0, bound=0;
  int status=10;
  cdfbin(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return get_result("cdfbin1", status, bound, p);
}

double cdflib_cdfbin_2(double p, double xn, double pr) {
  int which=2;
  double q=1.0-p, ompr=1.0-pr, s=0, bound=0;
  int status=10;
  cdfbin(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return get_result("cdfbin2", status, bound, s);
}

double cdflib_cdfbin_3(double p, double s, double pr) {
  int which=3;
  double q=1.0-p, ompr=1.0-pr, xn=0, bound=0;
  int status=10;
  cdfbin(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return get_result("cdfbin3", status, bound, xn);
}

double cdflib_cdfbin_4(double p, double s, double xn) {
  int which=4;
  double q=1.0-p, ompr=0, pr=0, bound=0;
  int status=10;
  cdfbin(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return get_result("cdfbin4", status, bound, pr);
}

double cdflib_cdfchi_1(double x, double df) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfchi(&which, &p, &q, &x, &df, &status, &bound);
  return get_result("cdfchi1", status, bound, p);
}

double cdflib_cdfchi_2(double p, double df) {
  int which=2;
  double q=1.0-p, x=0, bound=0;
  int status=10;
  cdfchi(&which, &p, &q, &x, &df, &status, &bound);
  return get_result("cdfchi2", status, bound, x);
}

double cdflib_cdfchi_3(double p, double x) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdfchi(&which, &p, &q, &x, &df, &status, &bound);
  return get_result("cdfchi3", status, bound, df);
}

double cdflib_cdfchn_1(double x, double df, double nc) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfchn(&which, &p, &q, &x, &df, &nc, &status, &bound);
  return get_result("cdfchn1", status, bound, p);
}

double cdflib_cdfchn_2(double p, double df, double nc) {
  int which=2;
  double q=1.0-p, x=0, bound=0;
  int status=10;
  cdfchn(&which, &p, &q, &x, &df, &nc, &status, &bound);
  return get_result("cdfchn2", status, bound, x);
}

double cdflib_cdfchn_3(double x, double p, double nc) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdfchn(&which, &p, &q, &x, &df, &nc, &status, &bound);
  return get_result("cdfchn3", status, bound, df);
}

double cdflib_cdfchn_4(double x, double df, double p) {
  int which=4;
  double q=1.0-p, nc=0, bound=0;
  int status=10;
  cdfchn(&which, &p, &q, &x, &df, &nc, &status, &bound);
  return get_result("cdfchn4", status, bound, nc);
}

double cdflib_cdff_1(double dfn, double dfd, double f) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdff(&which, &p, &q, &f, &dfn, &dfd, &status, &bound);
  return get_result("cdff1", status, bound, p);
}

double cdflib_cdff_2(double dfn, double dfd, double p) {
  int which=2;
  double q=1.0-p, f=0, bound=0;
  int status=10;
  cdff(&which, &p, &q, &f, &dfn, &dfd, &status, &bound);
  return get_result("cdff2", status, bound, f);
}

double cdflib_cdff_3(double p, double dfd, double f) {
  int which=3;
  double q=1.0-p, dfn=0, bound=0;
  int status=10;
  cdff(&which, &p, &q, &f, &dfn, &dfd, &status, &bound);
  return get_result("cdff3", status, bound, dfn);
}

double cdflib_cdff_4(double dfn, double p, double f) {
  int which=4;
  double q=1.0-p, dfd=0, bound=0;
  int status=10;
  cdff(&which, &p, &q, &f, &dfn, &dfd, &status, &bound);
  return get_result("cdff4", status, bound, dfd);
}

double cdflib_cdffnc_1(double dfn, double dfd, double nc, double f) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return get_result("cdffnc1", status, bound, p);
}

double cdflib_cdffnc_2(double dfn, double dfd, double nc, double p) {
  int which=2;
  double q=1.0-p, f=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return get_result("cdffnc2", status, bound, f);
}

double cdflib_cdffnc_3(double p, double dfd, double nc, double f) {
  int which=3;
  double q=1.0-p, dfn=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return get_result("cdffnc3", status, bound, dfn);
}

double cdflib_cdffnc_4(double dfn, double p, double nc, double f) {
  int which=4;
  double q=1.0-p, dfd=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return get_result("cdffnc4", status, bound, dfd);
}

double cdflib_cdffnc_5(double dfn, double dfd, double p, double f) {
  int which=5;
  double q=1.0-p, nc=0, bound=0;
  int status=10;
  cdffnc(&which, &p, &q, &f, &dfn, &dfd, &nc, &status, &bound);
  return get_result("cdffnc5", status, bound, nc);
}

double cdflib_cdfgam_1(double scale, double shape, double x) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
  return get_result("cdfgam1", status, bound, p);
}

double cdflib_cdfgam_2(double scale, double shape, double p) {
  int which=2;
  double q=1.0-p, x=0, bound=0;
  int status=10;
  cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
  return get_result("cdfgam2", status, bound, x);
}

double cdflib_cdfgam_3(double scale, double p, double x) {
  int which=3;
  double q=1.0-p, shape=0, bound=0;
  int status=10;
  cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
  return get_result("cdfgam3", status, bound, shape);
}

double cdflib_cdfgam_4(double p, double shape, double x) {
  int which=4;
  double q=1.0-p, scale=0, bound=0;
  int status=10;
  cdfgam(&which, &p, &q, &x, &shape, &scale, &status, &bound);
  return get_result("cdfgam4", status, bound, scale);
}

double cdflib_cdfnbn_1(double s, double xn, double pr) {
  int which=1;
  double q=0, p=0, ompr=1.0-pr, bound=0;
  int status=10;
  cdfnbn(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return get_result("cdfnbn1", status, bound, p);
}

double cdflib_cdfnbn_2(double p, double xn, double pr) {
  int which=2;
  double q=1.0-p, s=0, ompr=1.0-pr, bound=0;
  int status=10;
  cdfnbn(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return get_result("cdfnbn2", status, bound, s);
}

double cdflib_cdfnbn_3(double s, double p, double pr) {
  int which=3;
  double q=1.0-p, xn=0, ompr=1.0-pr, bound=0;
  int status=10;
  cdfnbn(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return get_result("cdfnbn3", status, bound, xn);
}

double cdflib_cdfnbn_4(double s, double p, double xn) {
  int which=4;
  double q=1.0-p, pr=0, ompr=0, bound=0;
  int status=10;
  cdfnbn(&which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound);
  return get_result("cdfnbn4", status, bound, pr);
}

double cdflib_cdfnor_1(double mean, double std, double x) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfnor(&which, &p, &q, &x, &mean, &std, &status, &bound);
  return get_result("cdfnor1", status, bound, p);
}

double cdflib_cdfnor_2(double mean, double p, double std) {
  int which=2;
  double q=1.0-p, x=0, bound=0;
  int status=10;
  cdfnor(&which, &p, &q, &x, &mean, &std, &status, &bound);
  return get_result("cdfnor2", status, bound, x);
}

double cdflib_cdfnor_3(double p, double std, double x) {
  int which=3;
  double q=1.0-p, mean=0, bound=0;
  int status=10;
  cdfnor(&which, &p, &q, &x, &mean, &std, &status, &bound);
  return get_result("cdfnor3", status, bound, mean);
}

double cdflib_cdfnor_4(double mean, double p, double x) {
  int which=4;
  double q=1.0-p, std=0, bound=0;
  int status=10;
  cdfnor(&which, &p, &q, &x, &mean, &std, &status, &bound);
  return get_result("cdfnor4", status, bound, std);
}

double cdflib_cdfpoi_1(double s, double xlam) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdfpoi(&which, &p, &q, &s, &xlam, &status, &bound);
  return get_result("cdfpoi1", status, bound, p);
}

double cdflib_cdfpoi_2(double p, double xlam) {
  int which=2;
  double q=1.0-p, s=0, bound=0;
  int status=10;
  cdfpoi(&which, &p, &q, &s, &xlam, &status, &bound);
  return get_result("cdfpoi2", status, bound, s);
}

double cdflib_cdfpoi_3(double p, double s) {
  int which=3;
  double q=1.0-p, xlam=0, bound=0;
  int status=10;
  cdfpoi(&which, &p, &q, &s, &xlam, &status, &bound);
  return get_result("cdfpoi3", status, bound, xlam);
}

double cdflib_cdft_1(double df, double t) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return get_result("cdft1", status, bound, p);
}

double cdflib_cdft_2(double df, double p) {
  int which=2;
  double q=1.0-p, t=0, bound=0;
  int status=10;
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return get_result("cdft2", status, bound, t);
}

double cdflib_cdft_3(double p, double t) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return get_result("cdft3", status, bound, df);
}

double cdflib_cdftnc_1(double df, double nc, double t) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return get_result("cdftnc1", status, bound, p);
}

double cdflib_cdftnc_2(double df, double nc, double p) {
  int which=2;
  double q=1.0-p, t=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return get_result("cdftnc2", status, bound, t);
}

double cdflib_cdftnc_3(double p, double nc, double t) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return get_result("cdftnc3", status, bound, df);
}

double cdflib_cdftnc_4(double df, double p, double t) {
  int which=4;
  double q=1.0-p, nc=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return get_result("cdftnc4", status, bound, nc);
}