#include <bits/stdc++.h>
using namespace std;

int v[22];
int tmp[22];
int idx = 0;
bool visited[22];
int m, n;


void print()
{
  for(int i = 0; i < m; ++i)
  {
    cout << tmp[i] << " ";
  }
  cout << "\n";
}

void dfs(int i)
{
  if(i == m)
  {
   print();
    return;
  }
  for(int j = 0; j < n; ++j)
  {
    if(!visited[v[j]])
    {
      if(i == 0 || v[j] > tmp[i-1])
      {
        visited[v[j]] = true;
        tmp[idx++] = v[j];
        dfs(i+1);
        --idx;
        visited[v[j]] = false;
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
  {
    cin >> v[i];
  }
  dfs(0);

  return 0;
}