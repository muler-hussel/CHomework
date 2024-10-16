#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffleSong(int len, int song[]);

int main(void) {
  int len;
  printf("How many songs required ?");
  scanf("%i", &len);
  int song[len];
  for (int i = 0; i < len; i++) {
    song[i] = i + 1;
  }
  shuffleSong(len, song);
  for (int i = 0; i < len; i++) {
    printf("%i ", song[i]);
  }
  
  return 0;
}

void shuffleSong(int len, int song[len]) {
  int r;
  srand(time(0));
  for (int i = len - 1; i >= 0; i--) {
    int r = rand() % (i + 1);
    int tmp = song[r];
    song[r] = song[i];
    song[i] = tmp;
  }
}