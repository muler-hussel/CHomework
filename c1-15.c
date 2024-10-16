#include <stdio.h>

void f(int n);

int main(void) {
  int n;
  printf("Type in a number:");
  scanf("%i", &n);

  f(n);

  return 0;
}

void f(int n) {
  while (n != 1) {
    printf("%i\n", n);
    if (n % 2 == 0) n /= 2;
    else n = 3 * n + 1;
  }
  printf("%i\n", n);
}