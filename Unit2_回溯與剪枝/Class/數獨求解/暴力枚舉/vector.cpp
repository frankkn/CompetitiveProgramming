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

//當前row, col, subgrid有沒有重複用過的
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

//更新row, col, subgrid當前這格的使用情況
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

//檢查是否為合法數獨
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
      if(grid[i][j] == 0) continue;
      if(illegal(i, j, grid[i][j], row, col, subgrid))
      {
        return false;
      }
      update(i, j, grid[i][j], true, row, col, subgrid);
    }
  }
  return true;
}

// 0~idx-1的格子都填好了
bool dfs
(
  int idx,
  vector<vector<int>>& grid,
  vector<vector<bool>>& row,
  vector<vector<bool>>& col,
  vector<vector<vector<bool>>>& subgrid
)
{
  if(idx == 81)
  {
    for(int i = 0; i < 9; ++i){
      fill(row[i].begin(), row[i].end(), 0);
      fill(col[i].begin(), col[i].end(), 0);
    }
    for(int i = 0; i < 3; ++i){
      for(int j = 0; j < 3; ++j){
        fill(subgrid[i][j].begin(), subgrid[i][j].end(), 0);
      }
    }
    return check(grid, row, col, subgrid);
  }

  int r = idx / 9;
  int c = idx % 9;
  if(grid[r][c])
  { 
    return dfs(idx+1, grid, row, col, subgrid); 
  }

  for(int i = 1; i <= 9; ++i)
  {
    grid[r][c] = i;
    if(dfs(idx+1, grid, row, col, subgrid))
    {
      return true;
    }
  }
  grid[r][c] = 0; // Backtrack must restore!!!
  return false;
}

int main()
{
  vector<vector<int>> grid(9,vector<int>(9,0));
  vector<vector<bool>> row(9,vector<bool>(10,0));
  vector<vector<bool>> col(9,vector<bool>(10,0));
  vector<vector<vector<bool>>> subgrid(3,vector<vector<bool>>(3,vector<bool>(10,0)));
  input(grid);
  if(check(grid, row, col, subgrid) && dfs(0, grid, row, col, subgrid)){
    print(grid);
  }else{
    cout << "No answer";
  }

  return 0;
}