#include <stdio.h>
#include <float.h>

int main(void) {
  int num;
  float max = FLT_MIN;
  printf("How many numbers do you wish to enter ?");
  scanf("%i", &num);
  float nums[num];
  printf("Enter %i real numbers:", num);

  for (int i = 0; i < num; i++) {
    scanf("%f", &nums[i]);
  }

  for (int i = 0; i < num; i++) {
    if (nums[i] - max > 0) max = nums[i];
  }

  printf("Maximum value: %.2f", max);
  return 0;
}