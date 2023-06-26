/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        // Nothing possible to start from zero
        if(s[0] == '0') 
            return 0;
        int n = s.size();
        vector<int> dp(n+1);
        // We can assume that the empty string is definitely "good"
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            if(s[i-1] != '0') dp[i] = dp[i-1];
            if(i-1 >= 1){
                int num = stoi(s.substr(i-2, 2));
                if(num >= 10 and num <= 26){
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

