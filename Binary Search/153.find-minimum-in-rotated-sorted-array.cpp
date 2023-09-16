/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int findMin(vector<int>& nums) {
        // At each index, check if we are in the left sorted half or the right
        // sorted half. If in left sorted half, move to the right, as there we
        // will find the minimum. If in the right sorted half, move towards left
        // to get lower into right sorted half.
        int l = 0, r = nums.size() - 1;
        int res = nums[0];
        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                return res;
            }
            int mid = l + (r - l) / 2;
            if (nums[l] > nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        return res;
    }
};
// @lc code=end
