/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prev(n);
        prev[0] = 1;
        for (int i = 0; i < m; i++) {
            vector<int> curr(n);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    curr[j] = 0;
                } else if (i == 0 and j == 0) {
                    curr[j] = 1;
                } else {
                    int left = j - 1 >= 0 ? curr[j - 1] : 0;
                    int up = i - 1 >= 0 ? prev[j] : 0;
                    curr[j] = left + up;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};
// @lc code=end
