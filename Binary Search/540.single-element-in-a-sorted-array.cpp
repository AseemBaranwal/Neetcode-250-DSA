/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        // Check odd element position and occurence
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (occurenceBefore(nums, m))
                h = m - 1;
            else
                l = m + 1;
        }
        return nums[l - 1];
    }

   private:
    inline bool occurenceBefore(vector<int>& nums, int idx) {
        return idx >= 1 and ((idx & 1) ^ (nums[idx - 1] == nums[idx]));
    }
};
// @lc code=end