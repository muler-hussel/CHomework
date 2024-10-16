#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define FI 1.61803398875

bool isvowel(char c);

int main(void) {
  char c;
  printf("Type in character");
  scanf("%c", &c);

  char ans = isvowel(c) ? toupper(c) : tolower(c);
  printf("%c", ans);
  
  return 0;
}

bool isvowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    return true;
  } else return false;
}