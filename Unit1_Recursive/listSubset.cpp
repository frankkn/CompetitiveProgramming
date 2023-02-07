/*
### input:
3

### output:
{}  
{2}  
{1}  
{1,2}  
{0}  
{0,2}  
{0,1}  
{0,1,2}  
*/

#include <iostream>
using namespace std;

int ans[25], m = 0;
int n;

void PrintSet()
{
  cout << '{';
  for(int i = 0; i < m; ++i)
  {
    if(i) cout << ',';
    cout << ans[i];
  }
  cout << "}\n";
}

void dfs(int i)
{
  if(i == n)
  {
    PrintSet();
    return;
  }
  dfs(i+1); // 不放入i
  ans[m++] = i; 
  dfs(i+1); // 放入i
  m--;
}

int main()
{
  cin >> n;
  dfs(0);
  return 0;
}