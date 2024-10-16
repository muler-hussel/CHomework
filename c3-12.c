#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define BIGSTR 1000

int convert(char s[]);

int main(void)
{
  ;
  assert(convert("MCMXCIX")==1999);
  
  assert(convert("MCMLXVII")==1967);
  
  assert(convert("MCDXCI")==1491);
  return 0;
}

int convert(char s[]) {
  int ans = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'M'){
      ans += 1000;
    } else if (s[i] == 'D') {
      ans += 500;
    } else if (s[i] == 'L') {
      ans += 50;
    } else if (s[i] == 'V') {
      ans += 5;
    } else if (s[i] == 'C') {
      if (s[i + 1] != '\0' && (s[i + 1] == 'M' || s[i + 1] == 'D')) ans-= 100;
      else ans += 100;
    } else if (s[i] == 'X') {
      if (s[i + 1] != '\0' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ans-= 10;
      else ans += 10;
    } else if (s[i] == 'I') {
      if (s[i + 1] != '\0' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ans-= 1;
      else ans += 1;
    }
  }
  return ans;
}