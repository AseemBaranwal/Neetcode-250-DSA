/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string &s) {
        unordered_set<char> set;
        int l = 0, res = 0;
        for(int r = 0; r < s.size(); r++) {
            while(set.find(s[r]) != set.end()) {
                set.erase(s[l++]);
            }
            set.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};

// @lc code=end