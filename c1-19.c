  #include <stdio.h>

  int differ(int a, int b, int c, int d);

  int main(void) {
    int aHour, aMin, bHour, bMin, diff;
    printf("print start time");
    scanf("%i:%i", &aHour, &aMin);
    printf("print end time");
    scanf("%i:%i", &bHour, &bMin);

    diff = differ(aHour, aMin, bHour, bMin);
    printf("Difference is : %02i:%02i", diff / 60, diff % 60);
    
    return 0;
  }

  int differ(int a, int b, int c, int d) {
    int diff;
    
    int startTime = a * 60 + b;
    int endTime = c * 60 + d;

    if (startTime < endTime) diff = endTime - startTime;
    else diff = endTime + 60 * 24 - startTime;

    return diff;
  }