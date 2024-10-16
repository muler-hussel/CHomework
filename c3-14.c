#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool fibword_phi(int n);

int main(void) {
  assert(fibword_phi(1) == 0);
  assert(fibword_phi(2) == 1);
  assert(fibword_phi(3) == 0);
  assert(fibword_phi(4) == 0);
  assert(fibword_phi(5) == 1);
  assert(fibword_phi(6) == 0);
  return 0;
}

bool fibword_phi(int n) {
  char s1[100000] = {'0', '\0'}, s2[100000] = {'0', '1', '\0'}, s3[100000];
  int r = 0;
  while (r < n) {
    strcpy(s3, s2);
    strcat(s3, s1);
    r = strlen(s3);
    strcpy(s1, s2);
    strcpy(s2, s3);
  }
  return s3[n - 1] - '0';
}
