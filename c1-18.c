#include <stdio.h>

int isT(int a, int b, int c);

int main(void) {
  int a, b, c;
  printf("prints 3 integers");
  scanf("%i%i%i", &a, &b, &c);

  if (isT(a, b, c) == 0) {
    printf("invalid data\n");
  } else {
    printf("correct data\n");
  }
  
  return 0;
}

int isT(int a, int b, int c) {
  if (a <= 0 || b <= 0 || c <= 0) return 0;
  else if (a + b <= c || a + c <= b || b + c <= a) return 0;
  else return 1;
}