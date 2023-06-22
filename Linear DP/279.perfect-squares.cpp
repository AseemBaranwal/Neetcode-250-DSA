// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem279.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        // Pay attention to the fact that the solution is always comprised of square additions
        // Hence it makes sense to get the total number of square additions
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int root = sqrt(i);
            if(root*root == i)
                dp[i] = 1;
            else{
                for(int j = 1; j*j <= i; j++){
                    dp[i] = min(dp[i], dp[i-j*j]+1);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

