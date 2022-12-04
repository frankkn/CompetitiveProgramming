#include <iostream>
#include <vector>
#include <queue>
#define INF 1e+9
using namespace std;

vector<long long> BFS(const vector<vector<int>> &G, int S) {
  int n = G.size(); // 假設點的編號為 0 ~ n-1
  vector<long long> d(n, INF);
  vector<bool> visited(n, false);
  queue<int> Q;
  Q.emplace(S);
  d[S] = 0; // 起點設 0
  while (Q.size()) 
  {
    //此時從queue拿出來時，d[u]已經是最短路徑了
    int u = Q.front();
    Q.pop();
    if (visited[u]) continue;
    visited[u] = true;
    for (auto v : G[u]) {
      if (d[v] > d[u] + 1)
      {
        d[v] = d[u] + 1;
        Q.emplace(v);
      }
    }
  }
  return d;
}
