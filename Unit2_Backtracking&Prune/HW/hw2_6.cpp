#include <iostream>
#include <string>

using namespace std;

int grid[9][9];
bool row[9][10];
bool col[9][10];
bool subgrid[3][3][10];

string s;
void update(int r, int c, int num, bool val);

void input()
{
  for(int i = 0; i < 81; ++i)
  {
    if(s[i] == '.')
    {
      grid[i/9][i%9] = 0;
    }
    else
    {
      grid[i/9][i%9] = s[i] - 48;
    }
  }
}

void print()
{
  for(int i = 0; i < 9; ++i)
  {
    for(int j = 0; j < 9; ++j)
    {
      cout << grid[i][j];
    }
  }
  cout << "\n";
}

bool illegal(int r, int c, int val)
{
  return row[r][val] || col[c][val] || subgrid[r/3][c/3][val];
}

bool check()
{
  for(int i = 0; i < 9; ++i)
  {
    for(int j = 0; j < 9; ++j)
    {
      if(grid[i][j] == 0) continue;
      if(illegal(i, j, grid[i][j]))	return false;
      update(i, j, grid[i][j], true);
    }
  }
  return true;
}

void update(int r, int c, int num, bool val)
{
  row[r][num] = val;
  col[c][num] = val;
  subgrid[r/3][c/3][num] = val;
}

bool dfs(int idx)
{
  if(idx == 81) return true;
  int r = idx/9, c = idx%9;
  if(grid[r][c]) return dfs(idx+1);

  for(int i = 1; i <= 9; ++i)
  {
    if(illegal(r, c, i)) { continue; }
    grid[r][c] = i;
    update(r, c, i, true);
    if(dfs(idx+1)) { return true; } // !!
    update(r, c, i, false);
  }
  grid[r][c] = 0;
  return false;
}

int main()
{
  while(cin >> s)
  {
    if(s != "end")
    { 
      memset(row, 0, sizeof(row));
      memset(col, 0, sizeof(col));
      memset(subgrid, 0, sizeof(subgrid));
      input();
      if(check() && dfs(0))
      {
        print();
      }
      else
      {
      	cout << "No solution.\n";
      }
    }
  }
  return 0;
}

