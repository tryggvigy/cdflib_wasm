#include "cdflib.h"

double cdft_1(double df, double t) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return p;
}

double cdft_2(double df, double p) {
  int which=2;
  double q=1.0-p, t=0, bound=0;
  int status=10;
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return t;
}

double cdft_3(double p, double t) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return df;
}

double cdftnc_1(double df, double nc, double t) {
  int which=1;
  double q=0, p=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return p;
}

double cdftnc_2(double df, double nc, double p) {
  int which=2;
  double q=1.0-p, t=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return t;
}

double cdftnc_3(double p, double nc, double t) {
  int which=3;
  double q=1.0-p, df=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return df;
}

double cdftnc_4(double df, double p, double t) {
  int which=4;
  double q=1.0-p, nc=0, bound=0;
  int status=10;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return nc;
}
