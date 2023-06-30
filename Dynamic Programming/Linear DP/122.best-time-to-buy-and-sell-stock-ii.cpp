// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem122.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // DP Problem - States: day, holding Stocks today or not
        int n = prices.size();
        int dp[n+1][2];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = -prices[0];
        for(int i = 1; i <= n; i++){
            dp[i][0] = max(dp[i-1][0], prices[i-1]+dp[i-1][1]);
            dp[i][1] = max(dp[i-1][1], -prices[i-1]+dp[i-1][0]);
        }
        return dp[n][0];
    }
};
// @lc code=end

