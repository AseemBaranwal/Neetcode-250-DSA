/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // The idea is to first of all work with all the modulo values and put them in prefixSum
        // Whenever we encounter the same prefixSum, it means we can get the index when it last 
        // occured and that window will be our answer. Beware of the EDGE CASES. Make sure you 
        // update hashmap only when value is not found or you end up updating the index.
        unordered_map<int, int> present;
        present[0] = -1;
        int preSum = 0;
        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            preSum %= k;
            if(present.find(preSum) != present.end()){
                if(i - present[preSum] > 1)
                    return true;
            }else
                present[preSum] = i;
        }
        return false;
    }
};
// @lc code=end

