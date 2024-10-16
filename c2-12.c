#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Choose {
  odd = 1, even, customize_num
} choose;

void oddEvenBet(choose s, int bet, int r);

int main(void) {
  choose s;
  int num, bet, r;
  srand(time(0));
  printf("Choose a way (1, 2, 3):");
  scanf("%u", &s);
  if (s == customize_num) {
    printf("Choose a number (0 to 35):");
    scanf("%i", &num);
  }
  
  printf("How much you want to bet:");
  scanf("%i", &bet);
  
  r = rand() % 36;
  if (s != customize_num) {
    oddEvenBet(s, bet, r);
  } else {
    if (r == bet) printf("You win %i", bet * 35);
    else printf("You lose %i", bet);
  }
  return 0;
}

void oddEvenBet(choose s, int bet, int r) {
  if (s == odd) {
    if (r % 2 == 0) printf("You lose %i", bet);
    else printf("You win %i", bet * 2);
  } else {
    if (r == 0) printf("You lose %i", bet);
    else if (r % 2 != 0) printf("You lose %i", bet);
    else printf("You win %i", bet * 2);
  }
}