#include <stdio.h>

int main(void) {
  int n, tri = 0;
  printf("How many Triangle numbers:");
  scanf("%i", &n);

  for (int i = 0; i < n; i++) {
    tri += i + 1;
    printf("%i\n", tri);
  }
  
  return 0;
}