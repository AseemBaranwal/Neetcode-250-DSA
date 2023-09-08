/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int dp[1005][1005];
    int minimizeMax(vector<int>& nums, int p) {
        // Greedy and then check whether we are taking the current element or
        // not. If we are taking the current element, then next call is made to
        // be max of current and solve(idx+2, p-1)
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        return solve(nums, p, 0);
    }

   private:
    int solve(vector<int>& nums, int p, int idx) {
        if (p == 0) return 0;
        if (idx + 1 >= nums.size()) return INT_MAX;
        if (dp[idx][p] > 0) return dp[idx][p];
        int ans1 = solve(nums, p, idx + 1);
        int ans2 = max(nums[idx + 1] - nums[idx], solve(nums, p - 1, idx + 2));
        return dp[idx][p] = ans1 == INT_MIN ? ans2 : min(ans1, ans2);
    }
};
// @lc code=end

/*
[10,1,2,7,1,3]
[1,1,2,3,7,10]
*/