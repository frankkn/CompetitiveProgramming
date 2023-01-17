// https://leetcode.com/problems/longest-increasing-subsequence/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  vector<int> DP(nums.size(), 0);
  int ans = 0;
  for(int i = 0; i < nums.size(); ++i)
  {
    for(int j = 0; j < i; ++j)
    {
      if(nums[i] > nums[j])
      {
        DP[i] = max(DP[i], DP[j]);
      }
    }
    DP[i] += 1;
    ans = max(ans, DP[i]);
  }
  cout << ans << endl;
  return 0;
}