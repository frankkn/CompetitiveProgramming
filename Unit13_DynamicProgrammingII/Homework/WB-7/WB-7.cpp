#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int MOD = 1000000007;

vector<vector<int>> Tree;

int DP[2][100000];// DP[0][u]:選白色; DP[1][u]:選黑色

void dfs(int u, int parent){
  DP[0][u] = 1;
  DP[1][u] = 1;

  for(auto v: Tree[u]){
    if(v == parent){
      continue;
    }
    dfs(v, u);
    DP[0][u] = (DP[0][u] * (DP[0][v] + DP[1][v])) % MOD; 
  }

  for(auto v: Tree[u]){
    if(v == parent){
      continue;
    }
    dfs(v, u);
    DP[1][u] = (DP[1][u] * DP[0][v]) % MOD; 
  }

}

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  Tree.assign(n+1, {});
  
  for(int i = 0; i < n-1; ++i){
    int u, v;
    cin >> u >> v;
    Tree[u].emplace_back(v);
    Tree[v].emplace_back(u);
  }

  dfs(1, -1);
  cout << (DP[0][1] + DP[1][1]) % MOD << "\n";

  return 0;
}