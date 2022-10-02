#include <iostream>
#include <cstring>
using namespace std;

int target, sz;
bool flag;
int num[12], ans[12];

void dfs(int idx, int m, int sum)
{
  int last = -1;
  if(sum > target)	return;
  if(sum == target)
  {
  	flag = false;
    for(int i = 0; i < m; ++i)
    {
      cout << ans[i] << "+\n"[i == m-1];
    }
    return;
  }
  for(int i = idx; i < sz; ++i)
  {
  	if(sum + num[i] > target)	continue;
    if(num[i] != last)
    {
      ans[m] = num[i];
      last = ans[m];
      dfs(i+1, m+1, sum+num[i]);
    }
  }
}

int main()
{
  while( cin >> target >> sz && (target || sz) )
  {
    flag = true;
    memset(num, 0, sizeof(num));
    for(int i = 0; i < sz; ++i)
    {
    	cin >> num[i];
    }
    cout << "Sums of " << target << ":\n";
    dfs(0,0,0);
    if(flag)
    {
    	cout << "NONE\n";
    }
  }
  return 0;
}