#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Tree;
vector<vector<int>> DP;

// int DP[2][100000];

//以u為root，pick=0/1(不挑或挑)的最大獨立集
void dfs(int u, int parent){
  DP[0][u] = 0;
  DP[1][u] = 1;

  for(auto v:Tree[u]){
    if(v == parent){
      continue;
    }
    dfs(v, u);
    DP[0][u] += max(DP[0][v], DP[1][v]); 
  }

  for(auto v:Tree[u]){
    if(v == parent){
      continue;
    }
    dfs(v, u);
    DP[1][u] += DP[0][v]; 
  }
}

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  Tree.assign(n+1, {});
  DP.assign(2, vector<int>(n+1, 0));

  for(int i = 0; i < n-1; ++i){
    int u, v;
    cin >> u >> v;
    Tree[u].emplace_back(v);
    Tree[v].emplace_back(u);
  }
  dfs(1, -1);
  cout << max(DP[0][1], DP[1][1]);

  return 0;
}