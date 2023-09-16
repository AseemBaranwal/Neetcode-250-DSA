/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        // Just take care where are you currently present in a rotated array
        // either the first sorted opart or the second sorted part. and then
        // decide what direction do you wanna go
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[m] >= nums[l]) {
                // left sorted half
                if (nums[m] < target) {
                    l = m + 1;
                } else if (nums[l] > target) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else {
                // right sorted half
                if (nums[m] >= target) {
                    r = m - 1;
                } else if (nums[r] < target) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    vector<int> v{5, 1, 3};
    int target = 3;
    cout << Solution().search(v, target) << endl;
}