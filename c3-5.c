#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void nextLine(int above[LEN], int next[LEN]);

int main(void) {
  int first[LEN], next[LEN];
  int r;
  srand(time(0));

  for (int i = 0; i < LEN; i++) {
    r = rand() % 10 > 5 ? 1 : 0;
    first[i] = r;
    printf("%i ", first[i]);
  }
  printf("\n");
  
  for (int i = 1; i < LEN; i++) {
    nextLine (first, next);
     for (int i = 1; i < LEN; i++) {
      first[i] = next[i];
     }
  }
  
  return 0;
} 

void nextLine(int above[LEN], int next[LEN]) {
  next[0] = next[LEN - 1] = 0;
  printf("%i ", next[0]);
  for (int i = 1; i < LEN - 1; i++) {
    int a = above[i - 1], b = above[i], c = above[i + 1];
    int sum = a * 100 + b * 10 + c;
    if (sum == 111 || sum == 100 || sum == 000) next[i] = 0;
    else next[i] = 1;
    printf("%i ", next[i]);
  }
   printf("%i\n", next[LEN - 1]);
}