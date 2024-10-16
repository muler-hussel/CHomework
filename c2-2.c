#include <stdio.h>
#include <math.h>

int main(void) {
  double x, sinX, cosX, ans;
  printf("Type in a real number:");
  scanf("%f", &x);

  sinX = sin(x);
  cosX = cos(x);
  ans = pow(sinX, 2) + pow(cosX, 2);

  printf("%.0f", ans);

  return 0;
} 