#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Tree;
vector<int> level;

void dfs(int u, int parent = -1) {
  if(parent == -1) level[u] = 0;
  else level[u] = level[parent] + 1;
  for (int v : Tree[u]) {
    if (v == parent) continue;
    dfs(v, u);
  }
}
