#include <stdio.h>
#include <math.h>
#include <float.h>

#define E 2.71828182818281849364

int main(void) {
  long a, b = 1, ansA, ansB;
  double min = DBL_MAX;

  for (; b < 100000; b++) {
    a = round(E * b);
    double diff = fabs((double)a / b - E);

    if (diff < min) {
      min = diff;
      ansA = a;
      ansB = b;
    }
  }

  printf("%li/%li = %f", ansA, ansB, (double)a / b);
  return 0;
} 