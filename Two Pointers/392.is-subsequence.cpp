/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        // This is not a DP problem. The dp problem is to find the longest common subsequence.
        // Here, just find the subsequence using the basic concept of two pointers
        int sidx = 0, tidx = 0;
        while(sidx < t.size() and tidx < t.size()){
            if(s[sidx] == t[tidx]) sidx++;
            tidx++;
        }
        return sidx == s.size();
    }
};
// @lc code=end

