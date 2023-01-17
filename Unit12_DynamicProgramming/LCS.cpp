// https://leetcode.com/problems/longest-common-subsequence/description/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> DP(m+1, vector<int>(n+1, 0));
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (text1[i-1] == text2[j-1]) {
          DP[i][j] = DP[i-1][j-1]+1;
        } else {
          DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
        }
        ans = max(ans, DP[i][j]);
      }
    }
    return ans;
  }
};