#include <iostream>
#include <queue>
#define MAXN 1000

int grid[MAXN][MAXN];

void bfs(int x, int y) {
  std::queue<std::pair<int,int>> Q;
  Q.emplace(x, y);
  while(Q.size()) {
    std::tie(x, y) = Q.front();
    Q.pop();
    if(grid[x][y]) continue;
    grid[x][y] = true;
    Q.emplace(x+1, y);
    Q.emplace(x, y+1);
    Q.emplace(x-1, y);
    Q.emplace(x, y-1);
  }
}
