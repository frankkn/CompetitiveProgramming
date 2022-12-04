#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G;
int n, m;
int main()
{
  cin >> n >> m;
  G.assign(n + 1, vector<int>(n + 1));
  while (m--) 
  {
    int u, v;
    cin >> u >> v;
    G[u][v] = G[v][u] = 1;
  }

  return 0;
}
