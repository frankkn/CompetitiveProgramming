#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> Dxy[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int grid[20][20];
void bfs(int x, int y) {
  queue<pair<int,int>> Q;
  Q.emplace(x, y);
  while(Q.size()) {
    tie(x, y) = Q.front();
    Q.pop();
    if(grid[x][y]) continue;
    grid[x][y] = true;
    for (auto [dx, dy] : Dxy) {
        Q.emplace(x + dx, y + dy);
    }
  }
}

vector<bool> visit;
vector<vector<int>> G;
void bfs(int u) {
  queue<int> Q;
  Q.emplace(u);
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    if (visit[u]) continue;
    visit[u] = true;
    for (auto v : G[u]) {
      Q.emplace(v);
    }
  }
}
