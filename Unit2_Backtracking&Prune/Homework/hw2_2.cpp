#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <string>
using namespace std;

int target, sz;
int num[13];
set<vector<int>> res;
vector<int> ans;

void print()
{
  int n = res.size();
  for(auto it = res.rbegin(); it != res.rend() ; ++it)
  {
    int m = (*it).size();
    for(int j = 0; j != m; ++j)
    {
      cout << (*it)[j] << "+\n"[j == m-1];
    }
  }
}

void dfs(int idx, int sum)
{
  if(sum > target)	return;
  if(sum == target)
  {
	res.insert(ans);
    return;
  }
  for(int i = idx; i < sz; ++i)
  {
  	if(sum + num[i] > target)	continue;
    ans.push_back(num[i]);
    dfs(i+1, sum+num[i]);
    ans.pop_back();
  }
}

int main()
{
  while( cin >> target >> sz && (target || sz) )
  {
    memset(num, 0, sizeof(num));
    for(int i = 0; i < sz; ++i) 
    { 
      cin >> num[i]; 
    }
    cout << "Sums of " << target << ":\n";
    dfs(0,0);
    print();
    if(res.empty()) { cout << "NONE\n"; }
    ans.clear();
    res.clear();
  }
  return 0;
}