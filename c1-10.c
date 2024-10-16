#include <stdio.h>
#define A 7
#define C 5
#define M 11

int main(void) {
  int seed = 0;
  for(int i = 0; i < M; i++) {
    seed = (A * seed + C) % M;
    printf("%i\n", seed);
  }
  return 0;
}