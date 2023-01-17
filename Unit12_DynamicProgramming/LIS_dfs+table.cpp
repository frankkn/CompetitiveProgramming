// https://leetcode.com/problems/longest-increasing-subsequence/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
vector<int> DP;

// dfs(i):計算以nums[i]為結尾的LIS
int dfs(int i)
{
  if(DP[i]) return DP[i];
  int ans = 0;
  for(int j = 0; j < i; ++j)
  {
    if(nums[i] > nums[j])
    {
      ans = max(ans, dfs(j));
    }
  }
  return DP[i] = ans+1;
}

int solve()
{
  int ans = 0;
  for(int i = 0; i < nums.size(); ++i)
  {
    ans = max(ans, dfs(i));
  }
  return ans;
}

int main()
{
  nums = {10, 9, 2, 5, 3, 7, 101, 18};
  DP.assign(nums.size(), 0);
  cout << solve() << endl;
  return 0;
}