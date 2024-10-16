#include "crossword.h"

bool isBlock(char c);
bool isBlank(char c);
void int2String(int idx, char strIdx[16]);

/*
   Convert a size (sz) & string (ip) into a crossword*
   White squares are ' ' or '.', black squares 'X' or '*'
*/
bool str2crossword(int sz, char *ip, crossword *cw)
{
  if (ip == NULL || sz < 0 || sz * sz != strlen(ip))
  {
    return false;
  }

  for (int i = 0; i < strlen(ip); i++)
  {
    cw->arr[i / sz][i % sz] = ip[i];
  }
  cw->sz = sz;
  return true;
}

// Convert crossword to string of across & down numbers
void getcluestring(const crossword *c, char *str)
{
  char strD[BIGSTR];
  int idx = 0, n = c->sz + 1, idxa = 0, idxd = 0;
  char newC[n][n];
  char strIdx[16];
  str[0] = 'A';
  strD[0] = 'D';
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == 0 || j == 0)
      {
        newC[i][j] = 'X';
      }
      else
      {
        newC[i][j] = c->arr[i - 1][j - 1];
      }
    }
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (isBlock(newC[i][j]))
        continue;
      else if ((isBlock(newC[i - 1][j]) && !isBlock(newC[i + 1][j])) || (isBlock(newC[i][j - 1]) && !isBlock(newC[i][j + 1])))
      {
        idx++;
        int2String(idx, strIdx);

        if (j + 1 < n && !isBlock(newC[i][j + 1]) && isBlock(newC[i][j - 1]))
        {
          int k = j;
          while (k < n && !isBlock(newC[i][k]))
          {
            if (isBlank(newC[i][k]))
            {
              newC[i][k] = '1';
            }
            else if (newC[i][k] == '1')
            {
              newC[i][k] = '2';
            }
            k++;
          }
          str[++idxa] = '-';
          for (int m = 0; m < strlen(strIdx); m++)
          {
            str[++idxa] = strIdx[m];
          }
        }
        if (i + 1 < n && !isBlock(newC[i + 1][j]) && isBlock(newC[i - 1][j]))
        {
          int k = i;
          while (k < n && !isBlock(newC[k][j]))
          {
            if (isBlank(newC[k][j]))
            {
              newC[k][j] = '1';
            }
            else if (newC[k][j] == '1')
            {
              newC[k][j] = '2';
            }
            k++;
          }
          strD[++idxd] = '-';
          for (int m = 0; m < strlen(strIdx); m++)
          {
            strD[++idxd] = strIdx[m];
          }
        }
      }
      printf("%c", newC[i][j]);
    }
    printf("\n");
  }
  str[++idxa] = '|';
  str[++idxa] = '\0';
  strD[++idxd] = '\0';
  strcat(str, strD);
  for (int i = 0; i < strlen(str); i++)
    printf("%c", str[i]);
}

// Get percentage of empty squares that are shared between two clues
int getchecked(crossword c)
{
  int n = c.sz + 1, cnt1 = 0, cnt2 = 0;
  char newC[n][n];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == 0 || j == 0)
      {
        newC[i][j] = 'X';
      }
      else
      {
        newC[i][j] = c.arr[i - 1][j - 1];
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (isBlock(newC[i][j]))
        continue;
      else if ((isBlock(newC[i - 1][j]) && !isBlock(newC[i + 1][j])) || (isBlock(newC[i][j - 1]) && !isBlock(newC[i][j + 1])))
      {
        if (j + 1 < n && !isBlock(newC[i][j + 1]) && isBlock(newC[i][j - 1]))
        {
          int k = j;
          while (k < n && !isBlock(newC[i][k]))
          {
            if (isBlank(newC[i][k]))
            {
              newC[i][k] = '1';
            }
            else if (newC[i][k] == '1')
            {
              newC[i][k] = '2';
            }
            k++;
          }
        }
        if (i + 1 < n && !isBlock(newC[i + 1][j]) && isBlock(newC[i - 1][j]))
        {
          int k = i;
          while (k < n && !isBlock(newC[k][j]))
          {
            if (isBlank(newC[k][j]))
            {
              newC[k][j] = '1';
            }
            else if (newC[k][j] == '1')
            {
              newC[k][j] = '2';
            }
            k++;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (newC[i][j] == '2')
        cnt2++;
      if (!isBlock(newC[i][j]))
        cnt1++;
    }
  }
  return (int)round(((float)cnt2 / cnt1) * 100);
}

bool isBlock(char c)
{
  return c == '*' || c == 'X';
}

bool isBlank(char c)
{
  return c == ' ' || c == '.';
}

void int2String(int idx, char strIdx[16])
{
  int i = 0;
  while (idx > 0)
  {
    strIdx[i++] = idx % 10 + '0';
    idx /= 10;
  }
  strIdx[i] = '\0';
  i--;
  int j = 0;
  while (j < i)
  {
    char c = strIdx[j];
    strIdx[j++] = strIdx[i];
    strIdx[i--] = c;
  }
}