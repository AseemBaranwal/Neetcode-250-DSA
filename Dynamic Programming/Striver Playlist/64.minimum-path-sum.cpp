/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 and j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int left = j - 1 >= 0 ? dp[i][j - 1] : 2000000;
                int up = i - 1 >= 0 ? dp[i - 1][j] : 2000000;
                dp[i][j] = grid[i][j] + min(left, up);
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
