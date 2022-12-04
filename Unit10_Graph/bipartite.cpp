#include <iostream>
#include <vector>
using namespace std;

vector<int> color; // 一開始初始化都是 0, 1:黑色, -1:白色
vector<vector<int>> G;
bool dfs(int u, int c = 1) 
{
  if (color[u])
    return color[u] == c;
  color[u] = c;
  for (auto v : G[u])
    if (!dfs(v, c * -1))
      return false;
  return true;
}
