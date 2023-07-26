/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0, n = nums.size();
        while (i < nums.size()) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    vector<int> temp{nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    j++;
                    while (j < k and nums[j] == nums[j - 1]) j++;
                }
            }
            i++;
            while (i < n and nums[i] == nums[i - 1]) i++;
        }
        return res;
    }
};
// @lc code=end
