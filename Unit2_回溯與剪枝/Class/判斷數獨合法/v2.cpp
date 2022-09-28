#include <iostream>
#include <vector>
#include <string>
using namespace std;

void input(vector<vector<int>>& grid)
{
  for(int i = 0; i < 9; ++i)
  {
    string s;
    cin >> s;
    for(int j = 0; j < 9; ++j)
    {
      if(!isdigit(s[j]))
      {
        grid[i][j] = 0;
      }
      else{
        grid[i][j] = s[j] - '0';
      }
    }
  }
}

void print(vector<vector<int>>& grid)
{
  for(int i {}; i < 9; ++i)
  {
    for(int j {}; j < 9; ++j)
    {
      cout << grid[i][j];
    }
    cout << "\n";
  }
}
bool illegal
(
  int i, int j, int num,
  vector<vector<bool>>& row,
  vector<vector<bool>>& col,
  vector<vector<vector<bool>>>& subgrid
)
{
  return (row[i][num] || col[j][num] || subgrid[i/3][j/3][num]);
}

void update
(
  int i, int j, int num,
  bool val,
  vector<vector<bool>>& row,
  vector<vector<bool>>& col,
  vector<vector<vector<bool>>>& subgrid
)
{
  row[i][num] = val;
  col[j][num] = val;
  subgrid[i/3][j/3][num] = val;
}


bool check
(
  vector<vector<int>>& grid,
  vector<vector<bool>>& row,
  vector<vector<bool>>& col,
  vector<vector<vector<bool>>>& subgrid
)
{
  for(int i = 0; i < 9; ++i)
  {
    for(int j = 0; j < 9; ++j)
    {
      if(illegal(i, j, grid[i][j], row, col, subgrid))
      {
        return false;
      }
      update(i, j, grid[i][j], true, row, col, subgrid);
    }
  }
  return true;
}

int main()
{
  vector<vector<int>> grid(9,vector<int>(9,0));
  vector<vector<bool>> row(9,vector<bool>(10,0));
  vector<vector<bool>> col(9,vector<bool>(10,0));
  vector<vector<vector<bool>>> subgrid(3,vector<vector<bool>>(3,vector<bool>(10,0)));
  input(grid);
  if(check(grid, row, col, subgrid)){
    cout << "Yes";
  }else{
    cout << "No";
  }

  return 0;
}