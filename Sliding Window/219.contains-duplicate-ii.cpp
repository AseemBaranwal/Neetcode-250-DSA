/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

#include <bitset>/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0, r = 0;
        unordered_map<int, int> mp;
        while (r < nums.size()) {
            if (r - l <= k) {
                mp[nums[r]]++;
                if (mp[nums[r]] > 1) return true;
                r++;
                continue;
            }
            mp[nums[l]]--;
            l++;
            mp[nums[r]]++;
            if (mp[nums[r]] > 1) return true;
            r++;
        }
        return false;
    }
};
// @lc code=end
