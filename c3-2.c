#include <stdio.h>

#define L 10 * 60
#define M 60
#define S 10

int numPress(int n);

int main(void) {
  int n;
  printf("Type the time required:");
  scanf("%i", &n);
  printf("Number of button presses = %i", numPress(n));
  return 0;
}

int numPress(int n) {
  int ans = 0;
  while (n > 0) {
    if (n >= L) {
      n -= L;
    } else if (n >= M) {
      n -= M;
    } else {
      n -= S;
    }
    ans++;
  }
  return ans;
}