#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    pair<int, int> binary_search(int L, int R, function<bool(int)> check)
    {
        if(check(R) == true)    return  {R, R+1};
        if(check(L) == false)    return  {L-1, L};
        while(L+1 < R)
        {
            int M = (L+R)/2;
            if(check(M))    L = M;   
            else    R = M;
        }
        return {L, R};
    }

    int search(vector<int> &nums, int target) {
        auto check_1 = [&](int idx){ return nums[idx] >= nums[0]; };
        auto [L, R] = binary_search(0, nums.size()-1, check_1);
        auto check_2 = [&](int idx){ return nums[idx] <= target; };
        int idx;
        
        // Special case: If original array is sorted
        if(R >= nums.size())
        {
            idx = binary_search(0, L, check_2).first;
            if(idx < 0) return -1;
            if(nums[idx] == target) return idx;
            else return -1;
        }
        
        // Case 1: Binary Search on the left part
        if(target >= nums[0])
        {      
            idx = binary_search(0, L, check_2).first;
        }
        // Case 2: Binary Search on the right
        else
        {
            idx = binary_search(R, nums.size()-1, check_2).first;
        }
        if(idx < 0) return -1;
        if(nums[idx] == target) return idx;
        else return -1;
    }
};