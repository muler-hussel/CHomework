#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define PHI 1.61

bool fibword_subs(int n);
int sub(int n);

int main(void) {
  int n = 1;
  while (fibword_subs(n) == sub(n)) {
    n++;
  }
  printf("%i", n);
  return 0;
} 

bool fibword_subs(int n) {
  int fib[2 * n];
  int idx = 0, i = 0;
  fib[0] = 0;
  while(i < n) {
    if (fib[i] == 0) {
      fib[++idx] = 1;
    }
    fib[++idx] = 0;
    i++;
  }
  return fib[n - 1];
}

int sub(int n) {
  return 2 + floor(n * PHI) - floor((n + 1) * PHI);
}