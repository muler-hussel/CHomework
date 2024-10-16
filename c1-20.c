#include <stdio.h>

int isPrime(int n);

int main(void) {
  int n, pri = 0, end3 = 0;
  float ans;
  printf("Type in a large number:");
  scanf("%i", &n);

  for (int i = 1; i <= n; i++) {
    if (isPrime(i) == 1) {
      pri++;
      if (i % 10 == 3) end3++;
    }
  }

  ans = (float) end3 / pri;
  printf("%.1f%", ans * 100);
} 

int isPrime(int n) {
  if (n == 1) return 1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}