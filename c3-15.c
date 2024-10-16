#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

void strmerge(const char* s1, const char* s2, char*s3);

#define LARGESTRING 1000

int main(void)
{
  char s[LARGESTRING];
  strmerge("Hello World!", "World! & Everyone.", s);
  assert(strcmp(s, "Hello World! & Everyone.")==0);
  strmerge("The cat sat", "sat on the mat.", s);
  assert(strcmp(s, "The cat sat on the mat.")==0);
  strmerge("The cat sat on the mat", "The cat sat on the mat.", s);
  assert(strcmp(s, "The cat sat on the mat.")==0);
  strmerge("One ", "Two", s);
  assert(strcmp(s, "One Two")==0);
  strmerge("", "The cat sat on the mat.", s);
  assert(strcmp(s, "The cat sat on the mat.")==0);
  strmerge("The cat sat on the mat.", "", s);
  assert(strcmp(s, "The cat sat on the mat.")==0);
  strmerge("123412341234", "1234", s);
  assert(strcmp(s, "123412341234")==0);
  strmerge("samsams", "samsabc", s);
  assert(strcmp(s, "samsamsabc")==0);
  strmerge("sasasas", "sasbsms", s);
  assert(strcmp(s, "sasasasbsms")==0);
  return 0;
}

void strmerge(const char* s1, const char* s2, char*s3) {
  int m = strlen(s1), n = strlen(s2), left = -1;
  if (m == 0) strcpy(s3, s1);
  if (n == 0) strcpy(s3, s2);
  bool dp[m + 1];
  for (int i = 0; i < m + 1; i++) dp[i] = true;
  
  bool pre = dp[0], curr = dp[1];
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m + 1; j++) {
      dp[j] = pre && s1[j - 1] == s2[i];
      if (j == m && dp[j] == true) {
        left = i;
        break;
      } else {
        pre = curr;
        if (j < m ) curr = dp[j + 1];
      }
    }
  }

  if (n == left) {
    strcpy(s3, s1);
  } else {
    char newS2[n - left];
    for (int i = left + 1; i < n; i++) newS2[i - left - 1] = s2[i];
    newS2[n - left - 1] = '\0';
    strcpy(s3, s1);
    strcat(s3, newS2);
  }
  
}