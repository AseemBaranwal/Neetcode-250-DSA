/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    string removeKdigits(string num, int k) {
        // Neetcode Monotonic Stack solution
        if(k == num.size()) return "0";
        stack<char> st;
        int idx = 0;
        while (idx < num.size() and k > 0) {
            while (k > 0 and !st.empty() and st.top() > num[idx]) {
                st.pop();
                k--;
            }
            st.push(num[idx++]);
        }
        while(k > 0){
            st.pop();
            k--;
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        if (idx < num.size()) res += num.substr(idx);
        int zCnt = 0;
        for (char ch : res) {
            if (ch != '0') break;
            zCnt++;
        }
        res = res.substr(zCnt);
        return res.size() == 0 ? "0" : res;
    }
};
// @lc code=end
