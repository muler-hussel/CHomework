#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int s = 0, l = 0, r;
  for (int i = 0; i < 500; i++) {
    r = rand() % 10 + 1;
    if (r <= 250) s++;
    else l++;
  }
  printf("%i", r - l);
  return 0;
}