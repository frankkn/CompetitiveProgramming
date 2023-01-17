#include <iostream>
#define MAXN 1000
using namespace std;

int grid[MAXN][MAXN];

pair<int, int> Dxy[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y) {
  if (grid[x][y]) return;
  grid[x][y] = true;
  for (auto [dx, dy] : Dxy)
    dfs(x + dx, y + dy);
}
