/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        int zeroCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i - zeroCnt] = nums[i];
            if (nums[i] == 0) zeroCnt++;
        }
        int i = nums.size() - 1;
        while (zeroCnt > 0) {
            nums[i] = 0;
            i--;
            zeroCnt--;
        }
    }
};
// @lc code=end
