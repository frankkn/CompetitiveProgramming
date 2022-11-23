#include <iostream>
#include <queue>
#define MAXN 1000

int grid[MAXN][MAXN];
int Level[MAXN][MAXN];

void bfs(int x, int y) {
  std::queue<std::pair<int, int>> Q;
  Q.emplace(x, y);
  int L = 0;
  while (Q.size()) {
    for (int Num = Q.size(); Num--;) {
      std::tie(x, y) = Q.front();
      Q.pop();
      if (grid[x][y])
        continue;
      grid[x][y] = true;
      Level[x][y] = L;
      Q.emplace(x + 1, y);
      Q.emplace(x, y + 1);
      Q.emplace(x - 1, y);
      Q.emplace(x, y - 1);
    }
    L += 1;
  }
}

