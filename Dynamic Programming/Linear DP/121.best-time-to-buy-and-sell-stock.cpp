/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, mn = prices[0];
        for(int i = 0; i < prices.size(); i++){
            res = max(res, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return res;
    }
};
// @lc code=end

