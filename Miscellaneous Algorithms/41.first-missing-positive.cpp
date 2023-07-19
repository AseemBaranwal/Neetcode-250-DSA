/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Cant do counting sort
        // No hashmap/hashset
        // In such a case, always try storing some value at index i, which can tell
        // something about whether it was present or not.
        // Refer - https://leetcode.com/problems/first-missing-positive/solutions/17071/my-short-c-solution-o-1-space-and-o-n-time/
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] <= n and nums[i] > 0 and nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1) 
                return i+1;
        }
        return n+1;
    }
};
// @lc code=end

