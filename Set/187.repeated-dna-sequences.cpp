/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> st, res;
        for(int i = 0; i < (int)s.size()-9; i++){
            string curr = s.substr(i, 10);
            if(st.find(curr) != st.end())
                res.insert(curr);
            st.insert(curr);
        }
        vector<string> repeatSequences;
        for(auto &ss: res){
            repeatSequences.push_back(ss);
        }
        return repeatSequences;
    }
};
// @lc code=end

