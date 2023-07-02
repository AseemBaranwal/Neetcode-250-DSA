/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // This problem can't be solved using the concept of two pointers and is different from
        // The problem of Kadane's algorithm as there can be negative numbers present as well
        // Hence we use a hashmap to store the number of prefix sums. Now for any element, if 
        // the hashMap[prefixSum - k] exists and is greater than zero, it means that we will 
        // directly use this, and there can be certain subarray which can be created from this
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int prefixSum = 0, subarrayCnt = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            subarrayCnt += cnt[prefixSum - k];
            cnt[prefixSum]++;
        }
        return subarrayCnt;
    }
};
// @lc code=end

