#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Tree;
vector<int> level;

void dfs(int u, int parent = -1){
  if(parent == -1){
    level[u] = 0;
  }else{
    level[u] = level[parent]+1;
  }

  for(auto v: Tree[u]){
    if(v == parent){
      continue;
    }
    dfs(v, u);
  }
}

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  Tree.assign(n+1, {});
  level.assign(n+1, 0);
  for(int i = 0; i < n-1; ++i){
    int u, v;
    cin >> u >> v;
    Tree[u].emplace_back(v);
    Tree[v].emplace_back(u);
  }

  dfs(1);
  int a = max_element(level.begin(), level.end()) - level.begin();
  dfs(a);
  int b = max_element(level.begin(), level.end()) - level.begin();
  cout << level[b] << endl;

  return 0;
}