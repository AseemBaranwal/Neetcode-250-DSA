/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        // Calculate the prefix Sum
        prefixSum.resize(nums.size());
        for(int i = 1; i < nums.size(); i++){
            prefixSum[i] += prefixSum[i-1]+nums[i-1];
        }
        prefixSum.push_back(prefixSum.back()+nums.back());
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
private:
    vector<int> prefixSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

