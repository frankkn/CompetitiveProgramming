// https://atcoder.jp/contests/dp/tasks/dp_g
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define int long long int
using namespace std;

vector<vector<int>> rG;

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  // 反著存圖 
  // vector<vector<int>> rG;
  int n, m;
  cin >> n >> m;
  rG.assign(n + 1, {});
  while (m--) {
    int u, v;
    cin >> u >> v;
    rG[v].emplace_back(u);
  }
  return 0;
}

vector<int> DP;
int dfs(int v) {
  if (DP[v] != -1) return DP[v];
  for (int u : rG[v])
    DP[v] = max(DP[v], dfs(u));
  return DP[v] += 1;
}

int solve(int n) {
  DP.assign(rG.size(), -1);
  int ans = 0;
  for (int v = 1; v <= n; ++v)
    ans = max(ans, dfs(v));
  return ans;
}
