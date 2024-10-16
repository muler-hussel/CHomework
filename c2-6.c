#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define FI 1.61803398875

bool fibword_phi(int n);

int main(void) {
  int n;
  printf("Type in a large number");
  scanf("%i", &n);

  printf("%d", fibword_phi(n));
  
  return 0;
}

bool fibword_phi(int n) {
  int ans = 2 + floor(n * FI) - floor((n + 1) * FI);
  return ans;
}
