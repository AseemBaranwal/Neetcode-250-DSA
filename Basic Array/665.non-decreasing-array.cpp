/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int changes = 0;
        for(int i = 1; i < nums.size() and changes <= 1; i++){
            if(nums[i] < nums[i-1]) {
                changes++;
                if(i - 2 < 0 or nums[i-2] <= nums[i]) 
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        return changes <= 1;
    }
};
// @lc code=end

