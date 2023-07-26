/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
#define ll long long
class Solution {
   private:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, int l, int r, ll target, int k,
             vector<int> &path) {
        if (k == 2) {
            while (l < r) {
                ll sum = nums[l] + nums[r] - target;
                if (sum == 0) {
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    res.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    l++;
                    while (l < r and nums[l] == nums[l - 1]) l++;
                } else if (sum < 0)
                    l++;
                else
                    r--;
            }
        } else {
            while (l <= nums.size() - k) {
                path.push_back(nums[l]);
                dfs(nums, l + 1, r, target - nums[l], k - 1, path);
                path.pop_back();
                l++;
                while (l < r and nums[l] == nums[l - 1]) l++;
            }
        }
    }

   public:
    vector<vector<int>> fourSum(vector<int> &nums, int target, int k = 4) {
        if (nums.size() < k) return res;
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        dfs(nums, 0, nums.size() - 1, (ll)target, k, tmp);
        return res;
    }
};
// @lc code=end
