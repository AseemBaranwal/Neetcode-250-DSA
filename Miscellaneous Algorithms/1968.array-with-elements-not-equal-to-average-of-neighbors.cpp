/*
 * @lc app=leetcode id=1968 lang=cpp
 *
 * [1968] Array With Elements Not Equal to Average of Neighbors
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Make sure that whenever swap thing is done, keep doing it till the end.
        // Alternate way is to sort the array and then rearrange the array
        int n = nums.size();
        for(int i = 1; i+1 < n; i++){
            if(nums[i+1] - nums[i] == nums[i] - nums[i-1]){
                swap(nums[i], nums[i+1]);
            }
        }
        for(int i = n-2; i -1 >= 0; i--){
            if(nums[i+1] - nums[i] == nums[i] - nums[i-1]){
                swap(nums[i], nums[i+1]);
            }
        }
        return nums;
    }
};

// @lc code=end

