/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        vector<int> bounds(2);
        int maxSize = 0;
        for (int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while (l >= 0 and r < s.size() and s[l] == s[r]) {
                if (r - l + 1 > maxSize) {
                    bounds[0] = l;
                    bounds[1] = r;
                    maxSize = r - l + 1;
                }
                r++, l--;
            }
            l = i - 1, r = i;
            while (l >= 0 and r < s.size() and s[l] == s[r]) {
                if (r - l + 1 > maxSize) {
                    bounds[0] = l;
                    bounds[1] = r;
                    maxSize = r - l + 1;
                }
                r++, l--;
            }
        }
        return s.substr(bounds[0], bounds[1] - bounds[0] + 1);
    }
};
// @lc code=end
