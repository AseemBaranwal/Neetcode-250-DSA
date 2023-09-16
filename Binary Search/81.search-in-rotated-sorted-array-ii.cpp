/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        // The normal approach won't work because for testcase [1,0,1,1,1], we
        // won't know which half are we in right now. Hence we need some other
        // approach. If nums[low] == nums[mid], lower search space by 1 by
        // moving the pointer by 1
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return true;
            if (nums[m] > nums[l]) {
                // left sorted half
                if (nums[m] < target) {
                    l = m + 1;
                } else if (nums[l] > target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else if (nums[m] < nums[l]) {
                // right sorted half
                if (nums[m] > target) {
                    r = m - 1;
                } else if (nums[r] < target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                l += 1;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    vector<int> v{1, 0, 1, 1, 1};
    int target = 0;
    cout << Solution().search(v, target) << endl;
}