#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define LEN 20

int difficulty(int dart[LEN]);
void swap(int i, int j, int dart[LEN]);

int main(void) {
  int dart[LEN], ans[LEN], total;
  srand(time(0));

  for (int i = 0; i < LEN; i++) {
    dart[i] = i + 1;
  }
  total = difficulty(dart);
  
  for (long i = 0; i < 5000000; i++) {
    int m = rand() % 20;
    int n = rand() % 20;
    
    swap(m, n, dart);
    if (difficulty(dart) < total) {
      total = difficulty(dart);
      for (int j = 0; j < LEN; j++) ans[j] = dart[j];
    } else {
      swap(n, m, dart);
    }
  }

  printf("Total = %i : ", total);
  for (int i = 0; i < LEN; i++) {
    printf("%i ", ans[i]);
  }
  
  return 0;
} 

int difficulty(int dart[LEN]) {
  int res = 0;
  for (int i = 0; i < LEN; i++) {
    res += pow((dart[i % 20] + dart[(i + 1) % 20] + dart[(i + 2) % 20]), 2);
  }
  return res;
}

void swap(int i, int j, int dart[LEN]) {
  int tmp = dart[i];
  dart[i] = dart[j];
  dart[j] = tmp;
}