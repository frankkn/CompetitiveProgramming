#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

bool dfs(vector<int>& nums, int k, int cur_sum, int target, vector<bool>& used, int index)
{
  if(k == 0)	return true;
  if(cur_sum > target)	return false;
  if(cur_sum == target)	return dfs(nums, k-1, 0, target, used, 0);
  
  for(int i = index; i < used.size(); ++i)
  {
  	if(used[i]) continue;
    used[i] = true;
    cur_sum += nums[i];
    if(dfs(nums, k, cur_sum, target, used, index+1))	return true;
    used[i] = false;
    cur_sum -= nums[i];
    if(cur_sum == 0)	break;
  }
  return false;
}
  
  
bool k_way_partition(vector<int>& nums, int k)
{
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if(sum % k)	return false;
  int target = sum / k;
  vector<bool> used(nums.size(), false);
  return dfs(nums, k, 0, target, used, 0);
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> nums(n,0);
	for(auto& n_i:nums)	cin >> n_i;    
  	if(k_way_partition(nums, 4))	cout << "yes\n";
    else	cout << "no\n";
  }
  return 0;
}