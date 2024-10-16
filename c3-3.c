#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomSong(int len, int song[]);

int main(void) {
  int len;
  printf("How many songs required ?");
  scanf("%i", &len);
  int song[len];
  for (int i = 0; i < len; i++) {
    song[i] = 0;
  }
  randomSong(len, song);
  for (int i = 0; i < len; i++) {
    printf("%i ", song[i]);
  }
  
  return 0;
}

void randomSong(int len, int song[len]) {
  int r, i= 1;
  srand(time(0));
  while (i <= len) {
    r = rand() % len;
    if (song[r] == 0) {
      printf("%i\n", song[r]);
      song[r] = i;
      i++;
    }
  }
}