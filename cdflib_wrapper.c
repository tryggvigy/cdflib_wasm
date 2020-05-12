#include "cdflib.h"

double cdftnc_1(int which, double p, double q, double t, double df, double nc, int status, double bound) {
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return p;
}

double cdft_2(int which, double p, double q, double t, double df, int status, double bound) {
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return t;
}
