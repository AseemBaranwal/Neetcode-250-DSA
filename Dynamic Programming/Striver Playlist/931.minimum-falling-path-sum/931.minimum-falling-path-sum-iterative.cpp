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
        // Given a square matrix
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n));
        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int left = j-1 >= 0 ? dp[i-1][j-1] : INT_MAX;
                int middle = dp[i-1][j];
                int right = j+1 < n ? dp[i-1][j+1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(left, min(middle, right));
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
// @lc code=end

