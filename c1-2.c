#include <stdio.h>
int main(void)
{
  int a, b, c;
  printf("Input three integers: ");
  scanf("%i%i%i", &a, &b, &c);
  printf("Twice the sum of integers plus 7 is %i !", (a + b + c) * 2 + 7);
}