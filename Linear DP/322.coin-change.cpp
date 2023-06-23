/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        // Here dp[i] at each value denotes the minimum number of coints required from the given set
        // of coin denominations to make up the amount i
        dp[0] = 0;
        for(int coin: coins){
            if(coin <= amount){
                dp[coin] = 1;
            }
        }
        sort(coins.begin(), coins.end());
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size() and coins[j] <= i; j++){
                if(dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end

