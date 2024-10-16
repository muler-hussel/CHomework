
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define MAXROWS 20
#define WIDTH 5
#define HEIGHT 6
struct st
{
  char board[MAXROWS][WIDTH];
  int bottom;
};
typedef struct st state;
bool initialise(state *s, const char *str);
bool tostring(const state *s, char *str);
bool matches(state *s);
bool dropblocks(state *s);
void test(void);

bool allDots(const state *s, int i);
bool initialiseString(state *s, const char *str);
void match2Lower(state *s, int height);
void swap(char *a, char *b);

int main(void)
{

  test();

  assert(initialise(NULL, "") == false);
  state s;
  assert(initialise(&s, NULL) == false);
  // Input string too short (not a multiple of 5)
  assert(initialise(&s, "ABCDBCDAACDAABDAABCAABCDABCDA") == false);
  // Incorrect character '+'
  assert(initialise(&s, "ABCDBCDAACDAABDAABCAABCDABCD+A") == false);

  /*
  BBBDB
  CDAAC
  DAABD
  AABCA
  ABCDA
  BCAAA
  */
  // Well-formed string
  assert(initialise(&s, "BBBDBCDAACDAABDAABCAABCDABCAAA") == true);
  char str[WIDTH * MAXROWS + 1];
  assert(tostring(&s, str) == true);
  assert(strcmp(str, "BBBDBCDAACDAABDAABCAABCDABCAAA") == 0);

  assert(matches(&s) == true);
  /*
  ...DB
  CDAAC
  DAABD
  AABC.
  ABCD.
  BC...
  */
  assert(tostring(&s, str) == true);
  assert(strcmp(str, "...DBCDAACDAABDAABC.ABCD.BC...") == 0);

  assert(dropblocks(&s) == true);
  /*
  .....
  CD.D.
  DAAA.
  AAABB
  ABBCC
  BCCDD
  */
  assert(tostring(&s, str) == true);
  assert(strcmp(str, "CD.D.DAAA.AAABBABBCCBCCDD") == 0);

  /*
  .....
  CD.D.
  D....
  ...BB
  ABBCC
  BCCDD
  */
  assert(matches(&s) == true);
  assert(tostring(&s, str) == true);
  assert(strcmp(str, "CD.D.D.......BBABBCCBCCDD") == 0);
  assert(dropblocks(&s) == true);
  /*
  C..D.
  DD.BB
  ABBCC
  BCCDD
  */
  assert(tostring(&s, str) == true);
  assert(strcmp(str, "C..D.DD.BBABBCCBCCDD") == 0);

  /* File version */
  assert(initialise(&s, "./b1.txt") == true);
  assert(tostring(&s, str) == true);
  assert(strcmp(str, "BBBDBCDAACDAABDAABCAABCDABCAAA") == 0);

  /* Match at 3 (not 4) on left near top of board */
  assert(initialise(&s, "lft.txt") == true);
  assert(matches(&s) == true);
  assert(tostring(&s, str) == true);
  assert(strcmp(str, "ABCDE.BCDE.CDEF.DEFABCDEFCDEFADEFAB") == 0);

  // All of these can be matched on the first pass ...
  /*
  AAAAA
  AAAAA
  AAAAA
  AAAAA
  AAAAA
  AAAAA
  */
  assert(initialise(&s, "./a.txt") == true);
  assert(matches(&s) == true);
  assert(dropblocks(&s) == true);
  assert(tostring(&s, str) == true);
  // Board is empty -> empty string ""
  assert(strlen(str) == 0);
  assert(matches(&s) == false);

  /* Some of these3 are 'off' the screen so not matched
     on the first pass */
  /*
  CCCCC
  CCCCC
  CCCCC
  CCCCC
  CCCCC
  CCCCC
  CCCCC
  CCCCC
  */
  assert(initialise(&s, "./c.txt") == true);
  assert(matches(&s) == true);
  assert(dropblocks(&s) == true);
  assert(tostring(&s, str) == true);
  assert(strcmp(str, "CCCCCCCCCC") == 0);

  /* Big, complex starting data that you should
     be able to match and drop lots of times ... */
  assert(initialise(&s, "./fourteen.txt") == true);
  // Keep looping while we can make changes.
  for (int i = 0; i < 14; i++)
  {
    assert(matches(&s));
    assert(dropblocks(&s));
  }
  assert(tostring(&s, str) == true);
  assert(strcmp(str, "...B...ABEBCCDDAABAE") == 0);

  return 0;
}

bool initialise(state *s, const char *str)
{
  if (s == NULL || str == NULL)
  {
    return false;
  }
  FILE *fp = fopen(str, "r");
  if (fp == NULL)
  {
    return initialiseString(s, str);
  }
  char c;
  for (int i = 0; i < MAXROWS; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      if (c = fgetc(fp) != EOF)
      {
        return s->board[i][j] = c;
      }
      else
      {
        s->bottom = i;
      }
    }
  }
  fclose(fp);
  return true;
}

bool initialiseString(state *s, const char *str)
{
  int len = strlen(str);
  if (len % WIDTH != 0)
  {
    return false;
  }
  for (int i = 0; i < len; i++)
  {
    if (!isupper(str[i]) && str[i] != '.')
    {
      return false;
    }
  }
  for (int i = 0; str[i]; i++)
  {
    s->board[i / WIDTH][i % WIDTH] = str[i];
  }
  s->bottom = len / 5 - 1;
  return true;
}

bool tostring(const state *s, char *str)
{
  if (s == NULL || str == NULL)
  {
    return false;
  }
  int idx = 0, highest = 0;
  while (highest <= s->bottom)
  {
    if (allDots(s, highest))
    {
      highest++;
    }
    else
    {
      break;
    }
  }
  for (int i = highest; i <= s->bottom; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      str[idx++] = s->board[i][j];
    }
  }
  str[idx] = '\0';
  return true;
}

bool allDots(const state *s, int i)
{
  for (int j = 0; j < WIDTH; j++)
  {
    if (s->board[i][j] != '.')
    {
      return false;
    }
  }
  return true;
}

bool matches(state *s)
{
  if (s == NULL)
  {
    return false;
  }
  int height = s->bottom;
  match2Lower(s, height);
  int removed = 0;
  for (int i = height; i > height - 6; i--)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      if (islower(s->board[i][j]))
      {
        removed++;
        s->board[i][j] = '.';
      }
    }
  }
  return removed > 0;
}

void match2Lower(state *s, int height)
{
  for (int i = height; i > height - 6; i--)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      char c1 = tolower(s->board[i][j]);
      if (j < WIDTH - 2)
      {
        char c2 = tolower(s->board[i][j + 1]), c3 = tolower(s->board[i][j + 2]);
        if (c1 == c2 && c1 == c3)
        {
          s->board[i][j] = c1;
          s->board[i][j + 1] = c2;
          s->board[i][j + 2] = c3;
        }
      }

      if (i > height - 4)
      {
        char c4 = tolower(s->board[i - 1][j]), c5 = tolower(s->board[i - 2][j]);
        if (c1 == c4 && c1 == c5)
        {
          s->board[i][j] = c1;
          s->board[i - 1][j] = c4;
          s->board[i - 2][j] = c5;
        }
      }
    }
  }
}

bool dropblocks(state *s)
{
  if (s == NULL)
  {
    return false;
  }
  int height = s->bottom;

  for (int j = 0; j < WIDTH; j++)
  {
    for (int i = height; i >= 0; i--)
    {
      int idx = i - 1;
      if (s->board[i][j] == '.')
      {
        while (idx >= 0)
        {
          if (s->board[idx][j] != '.')
          {
            swap(&s->board[i][j], &s->board[idx][j]);
            break;
          }
          idx--;
        }
      }
    }
  }
  return true;
}

void swap(char *a, char *b)
{
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void test(void)
{
}