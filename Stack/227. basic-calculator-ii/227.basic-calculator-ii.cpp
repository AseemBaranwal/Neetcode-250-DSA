/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int calculate(string s) {
        // Keep current operation in check and execute whenever you get two
        // numbers or you are the last index
        stack<int> st;
        int num = 0;
        int currentOp = '+', idx = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                num *= 10;
                num += (ch - '0');
            }
            if ((!isdigit(ch) and !iswspace(ch)) or i == s.size() - 1) {
                if (currentOp == '+') {
                    st.push(num);
                } else if (currentOp == '-') {
                    st.push(-num);
                } else if (currentOp == '*') {
                    int topElement = st.top();
                    st.pop();
                    st.push(topElement * num);
                } else if (currentOp == '/') {
                    int topElement = st.top();
                    st.pop();
                    st.push(topElement / num);
                }
                num = 0;
                currentOp = ch;
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
// @lc code=end

int main() { cout << Solution().calculate("3+2*2") << endl; }