#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Tree;
vector<int> DP[2];

// int DP[2][100000];

//以u為root，pick=0/1(不挑或挑)的最大獨立集
int dfs(int u, int pick, int parent = -1){
  // 無法正確擋反覆遞迴
  // if(u == parent){
  //   return 0;
  // }

  if(DP[pick][u]){
    return DP[pick][u];
  }

  // 無法判斷root跟leaf 
  // if(Tree[u].size() == 1){ //leaf node(在Tree上只會有一個連回parent的node)
  //   return pick;
  // }

  for(auto v:Tree[u]){
    // if(v == parent){ continue; }
    if(pick == 0){
      DP[pick][u] += max(dfs(v, 0, u), dfs(v, 1, u)); 
    }else{
      DP[pick][u] += dfs(v, 0, u);
    }
  }

  return DP[pick][u] += pick;
}

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  Tree.assign(n+1, {});
  // DP.assign(2, vector<int>(n+1, 0));
  DP[0] = DP[1] = vector<int>(n + 1, 0);

  for(int i = 0; i < n-1; ++i){
    int u, v;
    cin >> u >> v;
    Tree[u].emplace_back(v);
    Tree[v].emplace_back(u);
  }

  cout << max(dfs(1, 0), dfs(1, 1));

  return 0;
}