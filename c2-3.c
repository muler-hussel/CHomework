#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int isInCircle(float x, float y);

int main(void) {
  int n, cnt = 0;
  printf("Type in a large number:");
  scanf("%i", &n);
  
  srand(time(0));

  for (int i = 0; i < n; i++) {
    float x = rand() / (float)RAND_MAX * 2.0 - 1.0;
    float y = rand() / (float)RAND_MAX * 2.0 - 1.0;
    //printf("%f %f\n", x, y);
    if (isInCircle(x, y) == 1) cnt++;
    
  }
    printf("%i\n", cnt);
  printf("PI equals to %.2f", (float) cnt / n * 4);
  return 0;
} 

int isInCircle(float x, float y) {
  if (pow(x, 2) + pow(y, 2) <= 1) {
    return 1;
  }
  return 0;
}