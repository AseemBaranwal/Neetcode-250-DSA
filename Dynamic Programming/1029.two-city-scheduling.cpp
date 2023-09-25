/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Treat it as filling values from A and B. dp[a][b] represents how many
        // candidates went to city A and city B
        memset(dp, -1, sizeof(dp));
        int n = costs.size();
        return solve(costs, 0, n / 2, n / 2);
    }

   private:
    int dp[105][105];
    int solve(vector<vector<int>>& costs, int idx, int cntA, int cntB) {
        if (idx == costs.size() and cntA == 0 and cntB == 0) return 0;
        if (dp[cntA][cntB] != -1) return dp[cntA][cntB];
        int res = INT_MAX;
        // Sent to cityA
        if (cntA > 0)
            res = solve(costs, idx + 1, cntA - 1, cntB) + costs[idx][0];
        // Sent to cityB
        if (cntB > 0)
            res =
                min(res, solve(costs, idx + 1, cntA, cntB - 1) + costs[idx][1]);
        return dp[cntA][cntB] = res;
    }
};
// @lc code=end

int main() {
    vector<vector<int>> v;
    v.push_back({10, 20});
    v.push_back({30, 200});
    v.push_back({400, 50});
    v.push_back({30, 20});
    cout << Solution().twoCitySchedCost(v) << endl;
}