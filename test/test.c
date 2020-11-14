#include <stdio.h>
#include "../cdflib/cdflib.h"

void algdiv_test() {
  double a=1,b=2;
  printf("\nalgdiv %.15f", algdiv(&a,&b));
}

void alngam_test() {
  double x=7;
  printf("\nalngam %.15f", alngam(&x));
}

void alnrel_test() {
  double a=1;
  printf("\nalnrel %.15f", alnrel(&a));
}

void apser_test() {
  double a = 0.00000001;
  double b = 0.001;
  double x = 0.01;
  double eps = 0.01;
  printf("\napser %.15f", apser(&a, &b, &x, &eps));
}

void basym_test() {
  double a = 16;
  double b = 17;
  double lambda = 0.01;
  double eps = 0.01;
  printf("\nbasym %.15f", basym(&a, &b, &lambda, &eps));
}

int main() {
  algdiv_test();
  alngam_test();
  alnrel_test();
  apser_test();
  basym_test();
  return 0;
}
