/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Get the first value which is not in decreasing order from the left and swap it with the 
        // value that was just larger. Now sort the remaining part from the swapped index to get 
        // the next permutation.
        int n = nums.size(), idx = n - 1;
        if(n == 1) return;
        while(idx-1 >= 0 and nums[idx] <= nums[idx-1]){
            idx--;
        }
        if(idx == 0 and nums[0] >= nums[1]){
            reverse(nums.begin(), nums.end());
            return;
        }
        int small = idx - 1;
        idx = n-1;
        while(idx >= 0 and nums[small] >= nums[idx]) idx--;
        swap(nums[small], nums[idx]);
        sort(nums.begin()+small+1, nums.end());
    }
};
// @lc code=end

