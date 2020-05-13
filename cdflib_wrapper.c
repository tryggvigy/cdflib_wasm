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
