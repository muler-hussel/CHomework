#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

void convert(char name[], char soundex[5]);
int code(char c);

int main(void)
{
  char soundex[5];
  convert("Washington", soundex);
  assert(strcmp(soundex, "W252")==0);
  convert("Wu", soundex);
  assert(strcmp(soundex, "W000")==0);
  convert("DeSmet", soundex);
  assert(strcmp(soundex, "D253")==0);
  convert("Gutierrez", soundex);
  assert(strcmp(soundex, "G362")==0);
  convert("Pfister", soundex);
  assert(strcmp(soundex, "P236")==0);
  convert("Jackson", soundex);
  assert(strcmp(soundex, "J250")==0);
  convert("Tymczak", soundex);
  assert(strcmp(soundex, "T522")==0);
  convert("Ashcraft", soundex);
  assert(strcmp(soundex, "A261")==0);
  
  return 0;
}

void convert(char name[], char soundex[5]) {
  soundex[0] = name[0];
  soundex[4] = '\0';
  int idx = 1, prev = code(name[0]);
  for (int i = 1; name[i] != '\0'; i++) {
    if (idx > 3) break;
    int in = code(name[i]);
    if (in == -2) {
      prev = in;
    } else {
      if (in != -1 && in != prev) {
        prev = in;
        soundex[idx++] = in + '0';
      }
    }
  }
  for (; idx <= 3; idx++) soundex[idx] = '0';
}

int code(char c) {
  c = tolower(c);
  if (c == 'b' || c == 'f' || c == 'p' || c == 'v') return 1;
  else if (c == 'c' || c == 'g' || c == 'j' || c == 'k' || c == 'q' || c == 's' || c == 'x' || c == 'z') {
    return 2;
  } else if (c == 'd' || c == 't') return 3;
  else if (c == 'l') return 4;
  else if (c == 'm' || c == 'n') return 5;
  else if (c == 'r') return 6;
  else if (c == 'w' || c == 'h') return -1;
  else return -2;
}