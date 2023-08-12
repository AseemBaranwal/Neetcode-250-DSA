/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        // Simple Backtracking problem
        vector<string> res;
        string curr;
        solve(res, curr, 0, 0, n);
        return res;
    }

   private:
    void solve(vector<string> &res, string &curr, int opCnt, int clCnt, int n) {
        if (opCnt == n and clCnt == n) {
            res.push_back(curr);
            return;
        }
        if (opCnt < n) {
            curr.push_back('(');
            solve(res, curr, opCnt + 1, clCnt, n);
            curr.pop_back();
        }
        if (clCnt < opCnt) {
            curr.push_back(')');
            solve(res, curr, opCnt, clCnt + 1, n);
            curr.pop_back();
        }
    }
};
// @lc code=end
