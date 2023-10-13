/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m));
        for (int j = m - 1; j >= 0; j--) dp[m - 1][j] = triangle[m - 1][j];
        for (int i = m - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
int main() {
    Solution sol;
    vector<vector<int>> s{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << sol.minimumTotal(s) << endl;
}