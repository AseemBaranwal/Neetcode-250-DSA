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
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        int minEle = INT_MAX;
        for (int i = 0; i < n; i++) {
            minEle = min(minEle, solve(matrix, n, 0, i, dp));
        }
        return minEle;
    }

   private:
    int solve(vector<vector<int>>& matrix, int& n, int i, int j,
              vector<vector<int>>& dp) {
        if (j == n or j < 0) return 999999;
        if (i == n - 1) return dp[i][j] = matrix[i][j];
        if (dp[i][j] != INT_MAX) return dp[i][j];
        return dp[i][j] =
                   matrix[i][j] + min(solve(matrix, n, i + 1, j - 1, dp),
                                      min(solve(matrix, n, i + 1, j, dp),
                                          solve(matrix, n, i + 1, j + 1, dp)));
    }
};
// @lc code=end
int main() {
    Solution sol;
    vector<vector<int>> s{{-19, 57}, {-40, -5}};
    cout << sol.minFallingPathSum(s) << endl;
};