#include <stdio.h>
#include <limits.h>

int main(void) {
  int max = INT_MIN, num;
  printf("How many integers do you wish to enter ?");
  scanf("%i", &num);
  printf("Enter %i integers: ", num);

  int nums[num];
  for (int i = 0; i < num; i++) {
    scanf("%i", &nums[i]);
  }

  for (int i = 1; i < num; i++) {
    if (nums[i] % 2 != 0 && nums[i] > max) max = nums[i];
  }

  printf("Maximum value: %i", max);

  return 0;
}