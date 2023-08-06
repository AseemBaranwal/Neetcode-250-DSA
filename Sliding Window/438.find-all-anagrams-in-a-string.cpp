/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        // Very similar idea as problem 567. Permutation in string
        vector<int> ans;
        unordered_map<char, int> mp;
        for (char &ch : p) mp[ch]++;
        int unique = mp.size();
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (mp.count(s[r])) {
                mp[s[r]]--;
                if (mp[s[r]] == 0) unique--;
            }
            if (r - l + 1 == p.size()) {
                if (unique == 0) ans.push_back(l);
                if(mp.count(s[l])){
                    mp[s[l]]++;
                    if(mp[s[l]] == 1) unique++;
                }
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end
