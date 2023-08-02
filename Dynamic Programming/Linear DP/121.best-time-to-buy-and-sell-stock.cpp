/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <bitset>/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // Kind of DP where we store what is the minimum value present on a
        // previous day
        int res = 0;
        int mnPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - mnPrice);
            mnPrice = min(mnPrice, prices[i]);
        }
        return res;
    }
};
// @lc code=end
