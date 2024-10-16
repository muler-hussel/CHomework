#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

bool isvowel(char c);

int main(void) {
  for (int i = 0; i < 26; i++) {
    if (isvowel('a' + i)) continue;
    for (int j = 0; j < 26; j++) {
      if (!isvowel('a' + j)) continue;
      for (int k = 0; k < 26; k++) {
        if (isvowel('a' + k)) continue;
        printf("%c%c%c", 'a' + i, 'a' + j, 'a' + k);
      }
    }
  }
  return 0;
}

bool isvowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
    return true;
  } else return false;
}