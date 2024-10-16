#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265

int main(void) {
  int n = 2;
  float ans = 4.0;
  while (fabs(PI - ans) > 1 / pow(10, 7)) {
    if (n % 2 == 1) {
      ans += (float) 4 / (n * 2 - 1); 
    } else {
      ans -= (float) 4 / (n * 2 - 1);
    }
    n++;
  }

  printf("Need %i iterations", n);
  return 0;
} 