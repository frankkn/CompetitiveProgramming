#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> Tree;
vector<int> tree_size;

int ans = -1;
int n = Tree.size();
void dfs(int u, int parent = -1) {
  tree_size[u] = 1;
  int max_son_size = 0;
  for (auto v : Tree[u]) {
    if (v == parent) continue;
    dfs(v, u);
    tree_size[u] += tree_size[v];
    max_son_size = max(max_son_size, tree_size[v]);
  }
  max_son_size = max(max_son_size, n - tree_size[u]);
  if (max_son_size <= n / 2) ans = u;
}
