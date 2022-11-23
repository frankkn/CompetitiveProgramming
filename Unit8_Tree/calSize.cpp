#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Tree;
vector<int> tree_size;

int dfs(int u, int parent = -1) 
{
  tree_size[u] = 1;
  for (int v : Tree[u]) {
    if (v == parent) continue;
    tree_size[u] += dfs(v, u);
  }
  return tree_size[u];
}
