/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Simulate -- Each row gets the half of extra from previous row on both
        // the sides of the glass
        double pyramid[105][105];
        memset(pyramid, 0.0, sizeof(pyramid));
        pyramid[0][0] = poured;
        for (int r = 0; r < query_row; r++) {
            for (int c = 0; c <= r; c++) {
                double extra = (pyramid[r][c] - 1) / 2;
                if (extra > 0) {
                    pyramid[r + 1][c] += extra;
                    pyramid[r + 1][c + 1] += extra;
                }
            }
        }
        return min((double)1, pyramid[query_row][query_glass]);
    }
};
// @lc code=end
