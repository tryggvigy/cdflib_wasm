double cdflib_cdftnc_power(int which, double p, double q, double t, double df, double nc, int status, double bound) {
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  return p;
}

double cdflib_cdft_power(int which, double p, double q, double t, double df, int status, double bound) {
  cdft(&which,&p,&q,&t,&df,&status,&bound);
  return t;
}

int main() {
  int which = 1;
  // double *p;
  double p = 0.0;
  // double *q;
  double q = 0.0;
  double t = 2.10092204024096;
  double df = 18.0;
  double nc = 1.42445665344;
  int status = 10;
  double bound = 0.0;
  cdftnc(&which, &p, &q, &t, &df, &nc, &status, &bound);
  printf("\ncdftnc -> p %lf", p);

  int which2 = 2;
  double p2 = 0.025;
  double q2 = 0.975;
  double t2 = 0.0;
  double df2 = 18.0;
  double nc2 = 1.42445665344;
  int status2 = 10;
  double bound2 = 0.0;
  cdft(&which2,&p2,&q2,&t2,&df2,&status2,&bound2);
  printf("\ncdft -> t2 %lf", t2);

  int which3 = 2;
  double p3 = 0.025;
  double q3 = 0.975;
  double t3 = 0.0;
  double df3 = 18.0;
  int status3 = 10;
  double bound3 = 0.0;
  printf("\ncdflib_cdft_power -> t %lf", cdflib_cdft_power(which3,p3,q3,t3,df3,status3,bound3));

  printf("\nfifmod %lu", fifmod(1,2));
  return 0;
}
