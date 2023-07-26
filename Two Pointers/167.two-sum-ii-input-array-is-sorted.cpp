/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sm = numbers[l] + numbers[r];
            if (sm < target)
                l++;
            else if (sm > target)
                r--;
            else
                return {l + 1, r + 1};
        }
        return {};
    }
};
// @lc code=end
