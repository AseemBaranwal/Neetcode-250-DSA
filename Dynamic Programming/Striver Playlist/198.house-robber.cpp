/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int a = nums[0], b = 0;
        for (int i = 1; i < nums.size(); i++) {
            int c = max(a, b + nums[i]);
            b = a;
            a = c;
        }
        return a;
    }
};
// @lc code=end

