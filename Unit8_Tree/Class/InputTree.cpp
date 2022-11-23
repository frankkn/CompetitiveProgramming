#include <iostream>
#include <vector>
using namespace std;

// Unrooted Tree
vector<vector<int>> Tree;
int main()
{
  int n;
  cin >> n;
  Tree.assign(n + 1, {});
  for (int i = 0; i < n - 1; ++i) 
  {
    int u, v;
    cin >> u >> v;
    Tree[u].emplace_back(v);
    Tree[v].emplace_back(u);  
  }
}

/*
// If weighted
vector<vector<pair<int, int>>> Tree;
int n;
cin >> n;
Tree.assign(n + 1, {});
for (int i = 0; i < n - 1; ++i) {
  int u, v, cost;
  cin >> u >> v >> cost;
  Tree[u].emplace_back(v, cost);
  Tree[v].emplace_back(u, cost);
}
*/
