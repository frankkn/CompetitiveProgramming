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
int cnt[25];
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
    if(cnt[j] == 0)  continue;
    --cnt[j];
    ans[m++] = j;
    dfs(i+1);
    ++cnt[j];
    --m;
  }
}

int main()
{
  cnt[0] = 2;
  cnt[1] = 3;
  cnt[2] = 1;
  n = 6;
  dfs(0);
  return 0;
}