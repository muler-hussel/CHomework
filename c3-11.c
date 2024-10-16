#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define BIGSTR 1000

void int2string(int i, char* str);
int main(void)
{
  char s[BIGSTR];
  int2string(0, s);
  assert(strcmp(s, "0")==0);
  int2string(10, s);
  assert(strcmp(s, "10")==0);
  int2string(99, s);
  assert(strcmp(s, "99")==0);
  int2string(124, s);
  assert(strcmp(s, "124")==0);
  int2string(3141, s);
  assert(strcmp(s, "3141")==0);
  int2string(-1000, s);
  assert(strcmp(s, "-1000")==0);
  return 0;
}

void int2string(int i, char* str) {
  int idx = 0, ii = i, iNew;
  if (i < 0) {
    ii = -i;
  }
  while (ii > 0) {
    str[idx++] = (ii % 10) + '0';
    ii /= 10;
  }
  if (i < 0) str[idx++] = '-';
  str[idx] = '\0';
  if (i == 0) str[0] = '0';
  int j = 0, k = idx - 1;
  while (j < k) {
    char tmp = str[j];
    str[j++] = str[k];
    str[k--] = tmp;
  }
}