/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int evalRPN(vector<string> &tokens) {
        stack<long long> st;
        for (string &token : tokens) {
            if (isOp(token)) {
                long long second = st.top();
                st.pop();
                long long first = st.top();
                st.pop();
                if (token == "+")
                    st.push(first + second);
                else if (token == "-")
                    st.push(first - second);
                else if (token == "*")
                    st.push(first * second);
                else if (token == "/")
                    st.push(first / second);
            } else {
                st.push(stol(token));
            }
        }
        return st.top();
    }

   private:
    inline bool isOp(string &s) {
        return s == "+" or s == "-" or s == "*" or s == "/";
    }
};
// @lc code=end
