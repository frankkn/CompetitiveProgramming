#include <bits/stdc++.h>
using namespace std;


void print(int m, vector<int>& tmp)
{
  for(int i = 0; i < m; ++i)
  {
    cout << tmp[i] << " ";
  }
  cout << "\n";
}

void dfs(int i, int n, int m, vector<int>& v, vector<int>& tmp, vector<bool>& visited)
{
  if(i == m)
  {
    print(m, tmp);
    return;
  }
  for(int j = 0; j < n; ++j)
  {
    if(!visited[v[j]])
    {
      if(i == 0 || v[j] > tmp[i-1])
      {
        visited[v[j]] = true;
        tmp.push_back(v[j]);
        dfs(i+1, n, m, v, tmp, visited);
        visited[v[j]] = false;
        tmp.pop_back();
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  vector<int> tmp;
  vector<bool> visited(n);
  for(int i = 0; i < n; ++i)
  {
    cin >> v[i];
  }
  dfs(0, n, m, v, tmp, visited);

  return 0;
}