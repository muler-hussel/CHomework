#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int input, s, l;
  while (true) {
    printf("How much money would you like ?");
    scanf("%i", &input);

    if (input % 20 == 0) {
      printf("OK , dispensing ...\n");
      break;
    } else {
      s = input / 20 * 20;
      l = s + 20;
      printf("I can give you %i or %i , try again .\n", s, l);
    }
  }
  
  return 0;
}