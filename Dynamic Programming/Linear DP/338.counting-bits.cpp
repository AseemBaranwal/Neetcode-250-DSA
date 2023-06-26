/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        if(n > 0) dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i/2] + bool(i%2);
        }
        return dp;
    }
};
// @lc code=end

