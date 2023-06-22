/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // This is the divide and conquer approach of solving this problem. Pay attention that
        // the solution calculates the maximum profit that can be achieved in the left half and
        // the maximum profit that can be achieved in the right half and then maximizes the sum
        // of it. This resultant maximum profit is our answer.
        int n = prices.size();
        vector<int> leftProfit(n), rightProfit(n);

        // calculate the maximum profit that can be achieved in the left half
        int minLeft = INT_MAX, lProfitMax = 0;
        for(int i = 0; i < n; i++) {
            minLeft = min(minLeft, prices[i]);
            lProfitMax = max(lProfitMax, prices[i]-minLeft);
            leftProfit[i] = lProfitMax;
        }

        // calculate the maximum profit that can be achieved in the right half
        int maxRight = INT_MIN, rProfitMax = 0;
        for(int i = n-1; i >= 0; i--) {
            maxRight = max(maxRight, prices[i]);
            rProfitMax = max(rProfitMax, maxRight - prices[i]);
            rightProfit[i] = rProfitMax;
        }

        int maximumProfit = rightProfit[0];
        for(int i = 1; i < n; i++) {
            maximumProfit = max(maximumProfit, leftProfit[i-1] + rightProfit[i]);
        }
        return maximumProfit;
    }
};
// @lc code=end

