/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int calculate(string s) {
        // Process elements one by one and whenever you encounter a sign, push
        // the previous number and add sign based on what operation you jusr
        // processed.
        int res = 0, sign = 1, currentNum = 0;
        stack<int> st;
        for (char &ch : s) {
            if (isdigit(ch)) {
                currentNum *= 10;
                currentNum += (ch - '0');
            } else if (ch == '+') {
                res += sign * currentNum;
                currentNum = 0;
                sign = 1;
            } else if (ch == '-') {
                res += sign * currentNum;
                currentNum = 0;
                sign = -1;
            } else if (ch == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (ch == ')') {
                res += sign * currentNum;
                currentNum = 0;
                sign = st.top();
                st.pop();
                res *= sign;
                res += st.top();
                st.pop();
            }
        }
        if (currentNum > 0) res += currentNum * sign;
        return res;
    }
};
// @lc code=end
