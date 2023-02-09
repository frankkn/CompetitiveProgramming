#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 15;
int n; // 點的編號為 0 ~ n-1
int dist[MAXN][MAXN];

vector<bool> used;
int ans;

void dfs(int x, int cost){
  bool isAllTrue = true;
  for(auto y : used){
    isAllTrue &= y;
  }
  if(isAllTrue && x == 0){
    ans = min(ans, cost);
    return;
  }

  for(int y = 0; y < n; ++y){
    if(y == x || used[y]){
      continue;
    }
    used[y] = true;
    dfs(y, cost + dist[x][y]);
    used[y] = false;
  }
}

int solve(){
  used.resize(n, false);
  ans = 0x3f3f3f3f; // kinda 10^9 or INF
  dfs(0, 0);
  return ans;
}

int main()
{
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> dist[i][j];
    }
  }

  cout << solve();

  return 0;
}