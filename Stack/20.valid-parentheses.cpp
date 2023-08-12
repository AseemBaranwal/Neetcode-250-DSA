/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool isValid(string s) {
        vector<int> st;
        for (char &ch : s) {
            if (ch == '(' or ch == '[' or ch == '{')
                st.push_back(ch);
            else {
                if (st.empty())
                    return false;
                else if (ch == ')' and st.back() == '(')
                    st.pop_back();
                else if (ch == ']' and st.back() == '[')
                    st.pop_back();
                else if (ch == '}' and st.back() == '{')
                    st.pop_back();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end
