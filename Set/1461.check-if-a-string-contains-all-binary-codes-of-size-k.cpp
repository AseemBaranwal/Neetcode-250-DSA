/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for(int i = 0; i < (int)s.size() - k + 1; i++){
            st.insert(s.substr(i, k));
            if(st.size() == pow(2, k))
                return true;
        }
        return false;
    }
};
// @lc code=end

