#include <iostream>
#include <vector>
using namespace std;

pair<int, int> Dxy[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int grid[20][20];
void dfs(int x, int y) 
{
  if (grid[x][y]) return;
  grid[x][y] = true;
  for (auto [dx, dy] : Dxy)
    dfs(x + dx, y + dy);
}

vector<bool> visit;
vector<vector<int>> G;
void dfs(int u) 
{
  if (visit[u]) return;
  visit[u] = true;
  for (auto v : G[u]) 
  {
    dfs(v);
  }
}
