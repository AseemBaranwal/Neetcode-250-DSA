/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int characterReplacement(string s, int k) {
        // Non-clever implementation is to update maxFreq by traversing through
        // the entire hashmap and getting the current maxvalue. O(26*N)

        // Clever implemntation is seeing that the maxFreq value will only cause
        // the result to increase if only we update our maxFreq by increasing
        // it, otherwise it won't be updated. O(N)
        vector<int> count(26, 0);
        int ans = 0, l = 0, maxFreq = 0;
        for (int r = 0; r < s.size(); r++) {
            maxFreq = max(maxFreq, 1 + count[s[r] - 'A']);
            count[s[r] - 'A']++;
            while (r - l + 1 - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @lc code=end
