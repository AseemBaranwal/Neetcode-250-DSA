/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    string removeDuplicates(string s, int k) {
        // Use a stack pair and store the count of the character being repeated
        // the number of times. Pop whenever you find the character being
        // repeated more than k times. If you find this, pop.
        stack<pair<char, int>> st;
        for (char &ch : s) {
            if (!st.empty() and st.top().first == ch) {
                auto val = st.top();
                st.pop();
                st.push({val.first, val.second + 1});
            } else {
                st.push({ch, 1});
            }
            if (!st.empty() and st.top().second >= k) st.pop();
        }
        string res;
        while (!st.empty()) {
            res += string(st.top().second, st.top().first);
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
