/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        int row = r;
        if (row < 0) return false;
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] > target)
                r = mid - 1;
            else if (matrix[row][mid] < target)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};
// @lc code=end
