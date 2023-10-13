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
        return max(0, track(grid, grid.size(), 0, 0, 0, 0));
    }

   private:
    int track(vector<vector<int>>& grid, const int& n, int r1, int c1, int r2,
              int c2) {
        if (r1 == n or r2 == n or c1 == n or c2 == n or grid[r1][c1] == -1 or
            grid[r2][c2] == -1) {
            return INT_MIN;
        }
        if (r1 == n - 1 and c1 == n - 1) return grid[r1][c1];
        if (r2 == n - 1 and c2 == n - 1) return grid[r2][c2];
        int cherries = 0;
        if (r1 == r2 and c1 == c2)
            cherries = grid[r1][c1];
        else
            cherries = grid[r1][c1] + grid[r2][c2];
        return cherries + max(max(track(grid, n, r1 + 1, c1, r2 + 1, c2),
                                  track(grid, n, r1, c1 + 1, r2, c2 + 1)),
                              max(track(grid, n, r1 + 1, c1, r2, c2 + 1),
                                  track(grid, n, r1, c1 + 1, r2 + 1, c2)));
    }
};
// @lc code=end
