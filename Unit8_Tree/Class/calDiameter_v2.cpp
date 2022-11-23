#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Tree;

vector<int> D1, D2; // 最遠、次遠距離
int ans = 0; // 直徑長度

void dfs(int u, int parent = -1) 
{
  D1[u] = D2[u] = 0;
  for (int v : Tree[u]) 
  {
    if (v == parent) continue;
    dfs(v, u);
    int dis = D1[v] + 1;
    if (dis > D1[u]) 
    {
      D2[u] = D1[u];
      D1[u] = dis;
    } else
      D2[u] = max(D2[u], dis);
  }
  ans = max(ans, D1[u] + D2[u]);
}
