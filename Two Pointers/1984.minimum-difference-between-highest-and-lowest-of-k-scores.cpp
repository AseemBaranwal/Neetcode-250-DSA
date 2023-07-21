/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min_difference = 1000001;
        for(int i = 0; i + k - 1 < nums.size(); ++i)
            min_difference = min(nums[i+k-1] - nums[i], min_difference);
        return min_difference;
    }
};
// @lc code=end

