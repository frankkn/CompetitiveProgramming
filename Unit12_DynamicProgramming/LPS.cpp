// https://leetcode.com/problems/longest-palindromic-subsequence/description/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
      int n = s.size();
      vector<vector<int>> DP(n, vector<int>(n, 0));
      for(int i = 0; i < n; ++i)
      {
        DP[i][i] = 1;
      }
      // 由小到大枚舉長度區間
      for(int len = 2; len <= n; ++len)
      {
        for(int l = 0; l+len <= n; ++l)
        {
          int r = l+len-1;
          if(s[l] == s[r])
          {
            DP[l][r] = DP[l+1][r-1]+2;
          }
          else
          {
            DP[l][r] = max(DP[l+1][r], DP[l][r-1]);
          }
        }
      }
      return DP[0][n-1];
    }
};