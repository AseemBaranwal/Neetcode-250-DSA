/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return max(0, track(grid, m, n, 0, 0, n - 1));
    }

   private:
    int dp[71][71][71];
    int track(vector<vector<int>>& grid, int& m, int& n, int r1, int c1,
              int c2) {
        if (c1 < 0 or c2 < 0 or c1 == n or c2 == n) return -1e6;
        if (r1 == m - 1) {
            if (c1 == c2)
                return grid[r1][c1];
            else
                return grid[r1][c1] + grid[r1][c2];
        }
        if (dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        int cherries = (c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r1][c2];
        int maxValue = -1e6;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                maxValue =
                    max(maxValue, track(grid, m, n, r1 + 1, c1 + i, c2 + j));
            }
        }
        return dp[r1][c1][c2] = cherries + maxValue;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> grid = {{8, 8, 10, 9, 1, 7}, {8, 8, 1, 8, 4, 7},
                                {8, 6, 10, 3, 7, 7}, {3, 0, 9, 3, 2, 7},
                                {6, 8, 9, 4, 2, 5},  {1, 1, 5, 8, 8, 1},
                                {5, 6, 5, 2, 9, 9},  {4, 4, 6, 2, 5, 4},
                                {4, 4, 5, 3, 1, 6},  {9, 2, 2, 1, 9, 3}};

    cout << Solution().cherryPickup(grid) << endl;

    return 0;
}