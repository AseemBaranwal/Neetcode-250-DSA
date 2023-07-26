/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;
        while (l < r) {
            int minHeight = min(height[l], height[r]);
            maxArea = max(maxArea, minHeight * (r - l));
            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return maxArea;
    }
};
// @lc code=end
