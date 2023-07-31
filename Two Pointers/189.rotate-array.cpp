/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        // First approach O(N), O(N) --- Use a new array to set values

        // Second approach O(N + k), O(k) --- Use the same array to modify, but
        // keep initial k values

        // Third approach O(N), O(1) -- Reverse the whole array and then reverse
        // the starting k elements and then the rest of the elements
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end
