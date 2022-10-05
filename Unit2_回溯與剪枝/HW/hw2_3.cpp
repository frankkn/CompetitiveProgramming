#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int MASK;

int lowbit(int x) { return (x & -x); }

bool dfs(vector<int>& nums, int k, int cur_sum, int target,int used)
{
  if(k == 0)	return true;
  if(cur_sum > target)	return false;
  if(cur_sum == target)	return dfs(nums, k-1, 0, target,used);
  int ori = used;
  for(int num = 0; used; used ^= num)
  {
  	num = lowbit(used);
    cur_sum += nums[__lg(num)];
    if(dfs(nums, k, cur_sum, target, ori^num))	return true;
	
    cur_sum -= nums[num];
    if(cur_sum == 0)	break;
  }
  return false;
}
  
  
bool k_way_partition(vector<int>& nums, int k)
{
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if(sum % k)	return false;
  int target = sum / k;
  int n = nums.size();
  int used = (1 << n)-1;
  return dfs(nums, k, 0, target, used);
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