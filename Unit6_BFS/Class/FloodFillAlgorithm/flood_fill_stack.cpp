#include <iostream>
#include <stack>
#define MAXN 1000

int grid[MAXN][MAXN];

void dfs(int x, int y){
  std::stack<std::pair<int,int>> STK;
  STK.emplace(x, y);
  while(STK.size()){
    std::tie(x, y) = STK.top();
    STK.pop();
    if(grid[x][y]) continue;
    grid[x][y] = true;
    STK.emplace(x+1, y);
    STK.emplace(x, y+1);
    STK.emplace(x-1, y);
    STK.emplace(x, y-1);
  }
}

void dfs(int x, int y) {
  if(grid[x][y]) return;
  grid[x][y] = true;
  dfs(x+1, y);
  dfs(x, y+1);
  dfs(x-1, y);
  dfs(x, y-1);
}
