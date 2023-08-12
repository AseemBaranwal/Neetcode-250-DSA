/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    string removeStars(string s) {
        // Can also be solved using Two pointers, thus doingit in single pass
        // and optimizing used space
        stack<char> st;
        for (char &ch : s) {
            if (ch == '*' and !st.empty())
                st.pop();
            else
                st.push(ch);
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
