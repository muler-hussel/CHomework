#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(char s[]);
int len(char s[]);

int main(void) {
  printf("%i", isPalindrome("kayak"));
  return 0;
} 

bool isPalindrome(char s[]) {
  int n = len(s), i = 0, j = n;
  while(i < j) {
    if (s[i++] != s[j--]) return false;
  }
  return true;
}

int len(char s[]) {
  int res = 0;
  while (s[res]) res++;
  return res - 1;
}