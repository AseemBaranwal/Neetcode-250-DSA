/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> running;
        solve(nums, res, 0, running);
        return res;
    }
private:
    void solve(vector<int> &nums, vector<vector<int>> &res, int idx, vector<int> &running){
        if(idx == nums.size()) {
            res.push_back(running);
            return;
        }
        running.push_back(nums[idx]);
        solve(nums, res, idx+1, running);

        running.pop_back();
        solve(nums, res, idx+1, running);
    }
};
// @lc code=end

