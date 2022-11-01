#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    // We push -sum into PQ since we want kth smallest
    priority_queue<vector<int>> PQ;
    set<vector<int>> visited;
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        // cur[0] = cur_sum of certain column
        // cur[1] ... cur[m] = cur pos of each row
        vector<int> cur(m+1, 0);
        
        // first pos in PQ is 0,...,0 and the sum is the first col
        for(auto& row: mat)
        {
            cur[0] -= row[0];
        }
        PQ.emplace(cur);
        visited.insert(cur);
        
        for(int t = 1; t < k; ++t)
        {
            cur = PQ.top();
            PQ.pop();
            // List all the next step
            for(int i = 1; i <= m; ++i)
            {
                if(cur[i] == n-1)   continue; // reach the last element in the row
                auto next = cur;
                ++next[i];
                next[0] -= (mat[i-1][next[i]] - mat[i-1][next[i]-1]);
                if(!visited.emplace(next).second)  continue;
                PQ.emplace(next);
            }
        }
        return -PQ.top().at(0);
    }
};
