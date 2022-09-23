#include <iostream>
using namespace std;

template<typename T>
void Swap(T& a, T& b) 
{
  T tmp {std::move(a)};
  a = std::move(b);
  b = std::move(tmp);
};

int a[25], n; // input
void PrintArray()
{
  for(int i = 0; i < n; ++i)
  {
    cout << a[i] << " \n"[i == n-1];
  }
}

void dfs(int i)
{
  if(i == n)
  {
    PrintArray();
  }
  for(int j = i; j < n; ++j)
  {
    Swap(a[i],a[j]);
    dfs(i+1);
    Swap(a[i],a[j]);
  }
}

int main()
{
  cin >> n;
  for(int i = 0; i < n; ++i)
  {
    a[i] = i;
  }
  dfs(0);
  return 0;
}