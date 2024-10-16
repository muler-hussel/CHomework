#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

bool isprime(int i, int j, int k);
bool isvowel(char c);

int main(void) {
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (isvowel(j+'a') == isvowel(i+'a')) continue;
      for (int k = 0; k < 26; k++) {
        if (isvowel(k+'a') != isvowel(i+'a')) continue;
        if (isprime(i, j, k)) {
          printf("%c%c%c\n", 'a'+i, 'a'+j, 'a'+k) ;
        }
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

bool isprime(int i, int j, int k) {
  int sum = i + j + k + 3;
  for (int i = 2; i * i <= sum; i++) {
    if (sum % i == 0) return false;
  }
  return true;
}