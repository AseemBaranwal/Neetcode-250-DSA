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
        memset(dp, -1, sizeof(dp));
        return profit(prices, 0, 1);
    }
private:
    int dp[5001][2];
    int profit(vector<int>& prices, int day, int buyToday){
        if(day >= prices.size())
            return 0;
        if(dp[day][buyToday] > 0)
            return dp[day][buyToday];
        if(buyToday){
            dp[day][buyToday] = max(-prices[day] + profit(prices, day + 1, 0), profit(prices, day + 1, 1));
        }else{
            dp[day][buyToday] = max(prices[day] + profit(prices, day + 2, 1), profit(prices, day + 1, 0));
        }
        return dp[day][buyToday];
    }
};
// @lc code=end

