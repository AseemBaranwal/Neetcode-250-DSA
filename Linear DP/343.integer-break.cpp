/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        // We see that every number can be broken down into any number of parts
        // This begs us to use Dynamic Programming
        vector<int> dp(n+1);
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i], max(dp[j], j) * max(dp[i-j], i-j));
            }
        }
        return dp[n];
    }
};
// @lc code=end

