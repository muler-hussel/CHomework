#include <ctype.h>
#include <stdio.h>

int secret(int a);

int main(void) {
  char input[1000];
  printf("Type in sentence");
  
  while (scanf("%s", input) != EOF) { 
    for (int i = 0; input[i] != '\0'; i++) {
      
      printf("%c", secret(input[i] - 'a') + 'a');
    }
    printf(" ");
  }
  return 0;
}

int secret(int a) {
  char c = a + 'a';
  if (isalpha(c)) {
    if (islower(c)) {
      return 'z' - c;
    } else {
      return 'Z' - c + 'A' - 'a';
    }
  }
  return c - 'a';
}