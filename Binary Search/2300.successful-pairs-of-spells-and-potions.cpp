/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> res;
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++) {
            long long minValue =
                success / spells[i] + bool(success % spells[i]);
            res.push_back(potions.end() - lower_bound(potions.begin(),
                                                      potions.end(), minValue));
        }
        return res;
    }
};
// @lc code=end
