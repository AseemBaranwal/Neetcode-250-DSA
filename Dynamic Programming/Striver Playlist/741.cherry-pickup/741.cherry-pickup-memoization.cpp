/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int cherryPickup(vector<vector<int>>& grid) {
        // The idea is to have two different people traverse find the two best
        // paths rather than one person going all the way down and then come
        // back. The reason behind this is that there might be some space that
        // might be getting calcuated two times which we don't want. Thus, a
        // simple idea is to use two different persons and send them down and
        // then find the best path. Make sure that whenever they both are at the
        // same cell, we count the value at that cell only once and not twice.
        memset(dp, -1, sizeof(dp));
        return max(0, track(grid, grid.size(), 0, 0, 0, 0));
    }

   private:
    int dp[51][51][51][52];
    int track(vector<vector<int>>& grid, const int& n, int r1, int c1, int r2,
              int c2) {
        if (r1 == n or r2 == n or c1 == n or c2 == n or grid[r1][c1] == -1 or
            grid[r2][c2] == -1) {
            return INT_MIN;
        }
        if (r1 == n - 1 and c1 == n - 1)
            return dp[r1][c1][r2][c2] = grid[r1][c1];
        if (r2 == n - 1 and c2 == n - 1)
            return dp[r1][c1][r2][c2] = grid[r2][c2];
        if (dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
        int cherries = (r1 == r2 and c1 == c2) ? grid[r1][c1]
                                               : grid[r1][c1] + grid[r2][c2];
        cherries += max(max(track(grid, n, r1 + 1, c1, r2 + 1, c2),
                            track(grid, n, r1, c1 + 1, r2, c2 + 1)),
                        max(track(grid, n, r1, c1 + 1, r2 + 1, c2),
                            track(grid, n, r1 + 1, c1, r2, c2 + 1)));
        return dp[r1][c1][r2][c2] = cherries;
    }
};
// @lc code=end
