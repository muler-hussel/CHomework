#include <stdio.h>

long hail(long n);

int main(void) {
  long ans = 0, max = 0;

  for (long i = 2; i < 10000000; i++) {
    long len = hail(i);
    if (len > max) {
      max = len;
      ans = i;
    }
  }
  printf("%li", ans);

  return 0;
}

long hail(long n) {
  long len = 1;
  while (n != 1) {
    if (n % 2 == 0) n /= 2;
    else n = 3 * n + 1;
    len++;
  }
  return len;
}