#include <stdio.h>

int isP(int n);

int main(void) {
  int n, i = 2;
  printf("prints out how many first primes?");
  scanf("%i", &n);

  while (n > 0) {
    if (isP(i) == 1) {
      printf("%i\n", i);
      n--;
    }
    i++;
  }
  
  return 0;
}

int isP(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}