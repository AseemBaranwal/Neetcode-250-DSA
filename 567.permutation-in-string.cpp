/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        // For the most optimized version, keep in mind that you would use a
        // hashmap as you also have to keep check whether the element was
        // already present or not, and before changing value in the hashmap
        // check whether the element was already present, if the element was
        // already present, do operation, else do nothing. Always check if the
        // value is equivalent with the size of the s1, if it is - check for
        // correct behaviour - if not, move left pointer - now add unique and
        // all just how you subtracted first
        unordered_map<int, int> cnts1;
        int unique = 0;
        for (char &ch : s1) {
            if (cnts1[ch - 'a'] == 0) unique++;
            cnts1[ch - 'a']++;
        }
        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            int curr = s2[r] - 'a';
            if (cnts1.count(curr)) {
                cnts1[curr]--;
                if (cnts1[curr] == 0) unique--;
            }
            if (r - l + 1 == s1.size()) {
                if (unique == 0) return true;
                if (cnts1.find(s2[l] - 'a') != cnts1.end()) {
                    cnts1[s2[l] - 'a']++;
                    if (cnts1[s2[l] - 'a'] == 1) unique++;
                }
                l++;
            }
        }
        return false;
    }
};

// @lc code=end
