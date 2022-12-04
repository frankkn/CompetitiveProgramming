#include <iostream>
#include <vector>
#include <queue>
#define INF 1e+9
using namespace std;

vector<vector<pair<int, int>>> G;
int main()
{
  int n, m;
  cin >> n >> m;
  G.assign(n + 1, {});
  while (m--) {
    int u, v, cost;
    cin >> u >> v >> cost;
    G[u].emplace_back(v, cost);
  }
}

vector<long long> dijkstra(const vector<vector<pair<int, int>>> &G, int S) 
{
  int n = G.size(); // 假設點的編號為 0 ~ n-1
  vector<long long> d(n, INF);
  vector<bool> visited(n, false);
  using QueuePair = pair<long long, int>;
  priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> Q;
  d[S] = 0; // 起點設 0
  Q.emplace(d[S], S);
  while (Q.size()) {
    int u = Q.top().second;
    Q.pop();
    if (visited[u]) continue;
    visited[u] = true;
    for (auto [v, cost] : G[u])
      if (d[v] > d[u] + cost) 
      {
        d[v] = d[u] + cost;
        Q.emplace(d[v], v);
      }
  }
  return d;
}
