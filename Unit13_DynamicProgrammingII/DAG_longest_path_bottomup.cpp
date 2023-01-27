// https://atcoder.jp/contests/dp/tasks/dp_g
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define int long long int
using namespace std;

vector<vector<int>> G;
vector<int> in;

int main()
{
  int n, m;
  cin >> n >> m;
  G.assign(n + 1, {});
  in.assign(n + 1, 0);
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    ++in[v];
  }
  return 0;
}

int solve(int n) {
  vector<int> DP(G.size(), 0);
  vector<int> Q;
  for (int u = 1; u <= n; ++u)
    if (in[u] == 0)
      Q.emplace_back(u);
  for (size_t i = 0; i < Q.size(); ++i) {
    int u = Q[i];
    for (auto v : G[u]) {
      DP[v] = max(DP[v], DP[u] + 1);
      if (--in[v] == 0)
        Q.emplace_back(v);
    }
  }
  return *max_element(DP.begin(), DP.end());
}
