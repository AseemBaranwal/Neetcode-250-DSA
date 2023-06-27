/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Keep in mind that you can't terminate the loop when you reach leftSum > rightSum as
        // -ve values are allowed
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(total - prefixSum - nums[i] == prefixSum){
                return i;
            }
            prefixSum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

