#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
void Swap(T& a, T& b) 
{
  T tmp {std::move(a)};
  a = std::move(b);
  b = std::move(tmp);
};

int ans[25], n, m = 0; // input
bool visited[25];
void PrintArray()
{
  for(int i = 0; i < n; ++i)
  {
    cout << ans[i] << " \n"[i == n-1];
  }
}


void dfs(int i)
{
  if(i == n)
  {
    PrintArray();
    return;
  }
  for(int j = 0; j < n; ++j)
  {
    if(visited[j])  continue;
    visited[j] = true;
    ans[m++] = j;
    dfs(i+1);
    visited[j] = false;
    --m;
  }
}

int main()
{
  cin >> n;
  dfs(0);
  return 0;
}