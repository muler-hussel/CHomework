#define MAXSQ 10
typedef struct board
{
  int grid[MAXSQ][MAXSQ];
  int w;
  int h;
  int totmines;
} board;

#define UNK '?'
#define MINE 'X'

board solve_board(board b)
{
  int dir[8][2] = {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {-1, -1}, {0, -1}, {1, -1}};
  int n = b.w, m = b.h, totalM = 0;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int c = b.grid[i][j];
      if (c == 0 || c == '?' - '0')
        continue;
      int unknow = 0, mine = 0;
      if (c >= 1 && c <= 9)
      {
        for (int k = 0; k < 8; k++)
        {
          int newI = i + dir[k][0], newJ = j + dir[k][1];
          if (newI >= 0 && newI < m && newJ >= 0 && newJ < n)
          {
            int cc = b.grid[newI][newJ];
            if (cc >= 0 && cc <= 9)
              continue;
            else if (cc == 'X' - '0')
              mine++;
            else
              unknow++;
          }
        }
        if (c == mine)
          continue;
        else if (c - mine == unknow)
        {
          for (int k = 0; k < 8; k++)
          {
            int newI = i + dir[k][0], newJ = j + dir[k][1];
            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n)
            {
              int cc = b.grid[newI][newJ];
              if (cc == '?' - '0')
              {
                b.grid[newI][newJ] = 'X' - '0';
                if (newI < i || (newI == i && newJ < j))
                  totalM++;
              }
            }
          }
        }
      }
      else if (c == 'X' - '0')
      {
        totalM++;
      }
      if (totalM == b.totmines)
      {
        for (int p = 0; p < m; p++)
        {
          for (int q = 0; q < n; q++)
          {
            if (b.grid[p][q] == '?' - '0')
            {
              int cnt = 0;
              for (int k = 0; k < 8; k++)
              {
                int newI = p + dir[k][0], newJ = q + dir[k][1];
                if (newI >= 0 && newI < m && newJ >= 0 && newJ < n)
                {
                  char cc = b.grid[newI][newJ];
                  if (cc == 'X' - '0')
                    cnt++;
                }
                b.grid[p][q] = cnt;
              }
            }
          }
        }
        break;
      }
    }
  }
  return b;
}

void board2str(char s[MAXSQ * MAXSQ + 1], board b)
{
  for (int i = 0; i < b.w * b.h; i++)
  {
    s[i] = b.grid[i / b.w][i % b.w] + '0';
  }
  s[b.w * b.h] = '\0';
}

bool syntax_check(unsigned totmines, unsigned width, unsigned height, char inp[MAXSQ * MAXSQ + 1])
{
  if (width * height != strlen(inp))
    return false;
  int mines = 0;
  for (int i = 0; i < strlen(inp); i++)
  {
    if (!isdigit(inp[i]) && inp[i] != '?' && inp[i] != 'X')
      return false;
    else if (inp[i] == 'X')
      mines++;
  }
  return mines <= totmines;
}

board make_board(int totmines, int width, int height, char inp[MAXSQ * MAXSQ + 1])
{
  struct board b;
  b.width = width;
  b.height = height;
  b.totmines = totmines;
  for (int i = 0; i < strlen(inp); i++)
  {
    b.grid[i / width][i % width] = inp[i] - '0';
  }
  return b;
}
