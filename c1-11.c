#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int r = rand() % 1000 + 1, curr;

  for (int i = 0; i < 10; i++) {
    printf("Type in a number:");
    scanf("%i", &curr);

    if (r == curr) {
      printf("Correct");
      break;
    } else if (r > curr) {
      printf("Too small.\n");
    } else {
      printf("Too large.\n");
    }

    if (i == 10) {
      printf("You failed.\n");
    }
  }
  return 0;
}