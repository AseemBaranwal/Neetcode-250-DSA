/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, currSum = 0;
        int res = nums.size() + 1;
        for (int r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            while (currSum >= target) {
                res = min(res, r - l + 1);
                currSum -= nums[l];
                l++;
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};
// @lc code=end
