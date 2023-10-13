/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Space = O(N)
        int n = matrix.size();
        vector<int> prev(matrix[0]);
        for(int i = 1; i < n; i++){
            vector<int> curr(n);
            for(int j = 0; j < n; j++){
                int left = j-1 >= 0 ? prev[j-1] : INT_MAX;
                int middle = prev[j];
                int right = j+1 < n ? prev[j+1] : INT_MAX;
                curr[j] = matrix[i][j] + min(left, min(middle, right));
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
// @lc code=end

