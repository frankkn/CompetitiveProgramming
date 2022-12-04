#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> G;
vector<int> in;
int main()
{
  int n, m;
  cin >> n >> m;
  G.assign(n + 1, {});
  in.assign(n + 1, 0);
  while (m--) 
  {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    ++in[v];
  }
}

vector<int> ans;
bool toposort(int n) 
{
  ans.clear();
  queue<int> Q;
  for (int u = 1; u <= n; ++u)
    if (in[u] == 0) Q.emplace(u);
  while (Q.size()) 
  {
    int u = Q.front();
    Q.pop();
    ans.emplace_back(u);
    for (auto v : G[u])
      if (--in[v] == 0) Q.emplace(v);
  }
  return ans.size() == n;
}

// vector<int> ans;
// bool toposort(int n) {
//   ans.clear();
//   for (int u = 1; u <= n; ++u)
//     if (in[u] == 0) ans.emplace_back(u);
//   for (size_t i = 0; i < ans.size(); ++i) {
//     int u = ans[i];
//     for (auto v : G[u])
//       if (--in[v] == 0) ans.emplace_back(v);
//   }
//   return ans.size() == n;
// }

