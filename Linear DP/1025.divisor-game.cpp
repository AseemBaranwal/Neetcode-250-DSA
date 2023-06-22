// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1025.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool divisorGame(int n) {
        vector<vector<bool>> dp(n+1, vector<bool> (2));
        // By default we understand that whenever any player in Bob or Alice reaches 1,
        // they have lost the game
        // Bob is assigned the state dp[i][0] and Alice is assigned the state dp[i][1]
        // dp[0] doesn't make sense as the n > 0

        // Dp value at any state signifies whether Alice wins in the current
        dp[1][0] = true, dp[1][1] = false;
        for(int i = 2; i <= n; i++){
            dp[i][0] = true;
            dp[i][1] = false;
            vector<int> divisors = findDivisiors(i);
            for(int div: divisors){
                dp[i][1] = dp[i-div][0] or dp[i][1];
                dp[i][0] = dp[i-div][1] and dp[i][0];
            }
        }
        return dp[n][1];
    }
private:
    vector<int> findDivisiors(int num){
        vector<int> divisors{1};
        for(int i = 2; i*i <= num; i++){
            if(num%i == 0){
                divisors.push_back(i);
                divisors.push_back(num/i);
            }
        }
        return divisors;
    }
};
// @lc code=end
