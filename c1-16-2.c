#include <stdio.h>

long hail(long n);

int main(void) {
  long ans = 0;

  for (long i = 2; i < 10000000; i++) {
    long max = hail(i);
    if (max > ans) {
      ans = max;
    }
  }
  printf("%li", ans);

  return 0;
}

long hail(long n) {
  long max = 0;
  while (n != 1) {
    if (n > max) max = n;
    if (n % 2 == 0) n /= 2;
    else n = 3 * n + 1;
  }
  return max;
}