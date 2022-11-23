#include <iostream>
#include <vector>
#include <algorithm>
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

int main()
{
  dfs(1); // 隨便選一個點
  int a = max_element(level.begin(), level.end()) - level.begin();
  dfs(a); // a 必然是直徑的其中一個端點
  int b = max_element(level.begin(), level.end()) - level.begin();
  cout << level[b] << endl;
}