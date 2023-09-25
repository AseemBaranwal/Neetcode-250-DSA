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
    int twoCitySchedCost(vector<vector<int>> &costs) {
        // The values are sorted based on the difference between the prices for
        // a and b for each person. At the end, choose 1 side all values to A
        // and other side all to B to find minimum
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] - a[1] < b[0] - b[1];
        });
        int res = 0;
        for (int i = 0; i < costs.size(); i++)
            res += i < costs.size() / 2 ? costs[i][0] : costs[i][1];

        return res;
    }
};
// @lc code=end
