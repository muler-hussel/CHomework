#include "bingrid.h"

bool isSolved(board *brd);
bool pairs(board *brd);
bool oxo(board *brd);
bool count(board *brd);

bool str2board(board *brd, char *str)
{
  int x = strlen(str);
  int sz = (int)sqrt(x);
  if (str == "" || sz % 2 != 0 || sz * sz != x)
    return false;
  for (int i = 0; i < x; i++)
  {
    brd->b2d[i / sz][i % sz] = str[i];
  }
  brd->sz = sz;
  return true;
}

void board2str(char *str, board *brd)
{
  int idx = 0;
  for (int i = 0; i < brd->sz; i++)
  {
    for (int j = 0; j < brd->sz; j++)
    {
      str[idx++] = brd->b2d[i][j];
    }
  }
  str[idx] = '\0';
}

bool isSolved(board *brd)
{
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < brd->sz; i++)
  {
    for (int j = 0; j < brd->sz; j++)
    {
      if (j < brd->sz - 2 && brd->b2d[i][j] == brd->b2d[i][j + 1] && brd->b2d[i][j + 2] == brd->b2d[i][j])
        return false;
      else if (i < brd->sz - 2 && brd->b2d[i][j] == brd->b2d[i + 1][j] && brd->b2d[i][j] == brd->b2d[i + 2][j])
        return false;
      else if (brd->b2d[i][j] == '1')
        cnt1++;
      else if (brd->b2d[i][j] == '0')
        cnt0++;
    }
  }
  return cnt0 == cnt1 && cnt0 == brd->sz * brd->sz / 2;
}

bool solve_board(board *brd)
{
  bool p, o, c;
  while (!isSolved(brd))
  {
    p = pairs(brd);
    o = oxo(brd);
    c = count(brd);
    if (p == false && o == false && c == false)
    {
      return false;
    }
  }
  return true;
}

void printboard(board *brd)
{
  for (int i = 0; i < brd->sz; i++)
  {
    for (int j = 0; j < brd->sz; j++)
    {
      printf("%c", brd->b2d[i][j]);
    }
  }
}

bool pairs(board *brd)
{
  bool flag = false;
  for (int i = 0; i < brd->sz; i++)
  {
    for (int j = 0; j < brd->sz; j++)
    {
      if (brd->b2d[i][j] == '.')
        continue;
      if (j < brd->sz - 1 && brd->b2d[i][j] == brd->b2d[i][j + 1])
      {

        if (j - 1 >= 0 && brd->b2d[i][j - 1] == '.')
        {
          flag = true;
          brd->b2d[i][j - 1] = brd->b2d[i][j] == '0' ? '1' : '0';
        }
        if (j + 2 < brd->sz && brd->b2d[i][j + 2] == '.')
        {
          flag = true;
          brd->b2d[i][j + 2] = brd->b2d[i][j] == '0' ? '1' : '0';
        }
      }
      else if (i < brd->sz - 1 && brd->b2d[i][j] == brd->b2d[i + 1][j])
      {

        if (i - 1 >= 0 && brd->b2d[i - 1][j] == '.')
        {
          flag = true;
          brd->b2d[i - 1][j] = brd->b2d[i][j] == '0' ? '1' : '0';
        }
        if (i + 2 < brd->sz && brd->b2d[i + 2][j] == '.')
        {
          flag = true;
          brd->b2d[i + 2][j] = brd->b2d[i][j] == '0' ? '1' : '0';
        }
      }
    }
  }
  return flag;
}

bool oxo(board *brd)
{
  bool flag = false;
  for (int i = 0; i < brd->sz; i++)
  {
    for (int j = 0; j < brd->sz; j++)
    {
      if (brd->b2d[i][j] == '.')
        continue;
      if (j < brd->sz - 2 && brd->b2d[i][j + 1] == '.' && brd->b2d[i][j] == brd->b2d[i][j + 2])
      {
        flag = true;
        brd->b2d[i][j + 1] = brd->b2d[i][j] == '0' ? '1' : '0';
      }
      else if (i < brd->sz - 2 && brd->b2d[i + 1][j] == '.' && brd->b2d[i][j] == brd->b2d[i + 2][j])
      {
        flag = true;
        brd->b2d[i + 1][j] = brd->b2d[i][j] == '0' ? '1' : '0';
      }
    }
  }
  return flag;
}

bool count(board *brd)
{
  for (int i = 0; i < brd->sz; i++)

  {
    int cnt0 = 0, cnt1 = 0;
    bool isEmpty = false;
    for (int j = 0; j < brd->sz; j++)
    {
      if (brd->b2d[i][j] == '0')
        cnt0++;
      else if (brd->b2d[i][j] == '1')
        cnt1++;
      else
        isEmpty = true;

      if (cnt0 == brd->sz / 2 && isEmpty)
      {
        for (int k = 0; k < brd->sz; k++)
        {
          if (brd->b2d[i][k] == '.')
            brd->b2d[i][k] = '1';
        }
        return true;
      }
      else if (cnt1 == brd->sz / 2 && isEmpty)
      {
        for (int k = 0; k < brd->sz; k++)
        {
          if (brd->b2d[i][k] == '.')
            brd->b2d[i][k] = '0';
        }
        return true;
      }
    }
  }
  for (int j = 0; j < brd->sz; j++)

  {
    int cnt0 = 0, cnt1 = 0;
    bool isEmpty = false;
    for (int i = 0; i < brd->sz; i++)
    {
      if (brd->b2d[i][j] == '0')
        cnt0++;
      else if (brd->b2d[i][j] == '1')
        cnt1++;
      else
        isEmpty = true;

      if (cnt0 == brd->sz / 2 && isEmpty)
      {
        for (int k = 0; k < brd->sz; k++)
        {
          if (brd->b2d[k][j] == '.')
            brd->b2d[k][j] = '1';
        }
        return true;
      }
      else if (cnt1 == brd->sz / 2 && isEmpty)
      {
        for (int k = 0; k < brd->sz; k++)
        {
          if (brd->b2d[k][j] == '.')
            brd->b2d[k][j] = '0';
        }
        return true;
      }
    }
  }
  return false;
}
