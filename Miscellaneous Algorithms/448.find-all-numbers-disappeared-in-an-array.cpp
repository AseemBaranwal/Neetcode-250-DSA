/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // We are using the idea that all the numbers are positive and are in the range [1, n]
        // Starting to traverse the array from the left and replace the numbers with their -ve
        // counterparts following the indexes at which they lead. By the end, the indexes which
        // are positive have the corresponding numbers missing
        
        for(int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i]) - 1;
            nums[idx] = -abs(nums[idx]);
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
};
// @lc code=end

