/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int> (2));
        for(int i = n-1; i >= 0; i--) {
            // Let us assume that current day the stock is not allowed to be bought
            dp[i][0] = max(dp[i+1][0], prices[i] + dp[i+2][1]);

            // Let us assume that the stock is allowed to be bought on the current day
            dp[i][1] = max(dp[i+1][1], -prices[i] + dp[i+1][0]);
        }
        return dp[0][1];
    }
};
// @lc code=end
