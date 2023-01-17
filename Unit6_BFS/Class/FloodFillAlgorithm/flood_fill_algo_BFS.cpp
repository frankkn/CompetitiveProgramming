#include <iostream>
#include <queue>
#define MAXN 1000
using namespace std;

int grid[MAXN][MAXN];
int Level[MAXN][MAXN];

pair<int, int> Dxy[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(int x, int y) {
  queue<pair<int, int>> Q;
  Q.emplace(x, y);
  int L = 0;
  while (Q.size()) {
    for (int Num = Q.size(); Num--;) {
      tie(x, y) = Q.front();
      Q.pop();
      if (grid[x][y]) continue;
      grid[x][y] = true;
      Level[x][y] = L;
      for (auto [dx, dy] : Dxy)
        Q.emplace(x + dx, y + dy);
    }
    L += 1;
  }
}