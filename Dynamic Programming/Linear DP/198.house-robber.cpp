/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        dp[1] = nums[0];
        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
        }
        return dp[n];
    }
};
// @lc code=end

