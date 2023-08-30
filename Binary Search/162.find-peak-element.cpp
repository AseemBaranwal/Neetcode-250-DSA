/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        // The idea is to find a bigger element on either side, whenever we have
        // a bigger element on either side, there is always a possibility of
        // getting a peak element, we would move in the direction of the peak
        // element and since we can return the index of any peak element, it
        // shouldn't be an issue to leave some space if we make sure that
        // wherever we are going, we are sure to find a peak element
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m > 0 and nums[m] < nums[m - 1])
                r = m - 1;
            else if (m < nums.size() - 1 and nums[m] < nums[m + 1])
                l = m + 1;
            else
                return m;
        }
        return -1;
    }
};
// @lc code=end
