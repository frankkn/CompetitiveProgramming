#include <bits/stdc++.h>
using namespace std;

int v[30] = {};
int tmp[30] = {};
int idx = 0;
//bool visited[30] = {};
int m, n;

void print()
{
  for(int i = 0; i < m; ++i)
  {
    cout << tmp[i] << " ";
  }
  cout << "\n";
}

void dfs(int i, int k)
{
  if(i == m)
  {
    print();
    return;
  }
  for(int j = k; j < n; ++j)
  {
    //if(!visited[v[j]])
    {
      if(i == 0 || v[j] > tmp[i-1])
      {
        //visited[v[j]] = true;
        tmp[i] = v[j];
        dfs(i+1,j);
        //--idx;
        //visited[v[j]] = false;
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
  {
    cin >> v[i];
  }
  dfs(0,0);
  return 0;
}