/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<pair<int, int>> st;  // {temperature, idx}
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and st.top().first <= temperatures[i]) st.pop();
            if (st.empty())
                res[i] = 0;
            else
                res[i] = st.top().second - i;
            st.push({temperatures[i], i});
        }
        return res;
    }
};
// @lc code=end
