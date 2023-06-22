/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return profit(prices, 0, 1, 0);
    }
    int profit(vector<int> &prices, int idx, int buyToday, int tradesDone){
        if(tradesDone == 2 or idx == prices.size())
            return 0;
        string currKey = to_string(idx) + "_" + to_string(buyToday) + "_" + to_string(tradesDone);
        if(dp.find(currKey) != dp.end())
            return dp[currKey];
        int holdToday, notHoldToday;
        if(buyToday){
            notHoldToday = profit(prices, idx+1, 1, tradesDone);
            holdToday = profit(prices, idx+1, 0, tradesDone) - prices[idx];
        }else{
            notHoldToday = profit(prices, idx+1, 1, tradesDone+1) + prices[idx];
            holdToday = profit(prices, idx+1, 0, tradesDone);
        }
        return dp[currKey] = max(holdToday, notHoldToday);
    }
    unordered_map<string, int> dp;
};
// @lc code=end

