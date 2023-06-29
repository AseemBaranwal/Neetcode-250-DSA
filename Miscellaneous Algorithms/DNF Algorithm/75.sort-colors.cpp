/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Solving this problem using DNF algorithm
        // We can also sort them using bucket sort by counting the instances of occurence of
        // 0, 1, and 2 and count the number of occurence and then overwrite the existing array in
        // place. However, this is not a time complexity of O(1)

        // Understand that whenever we make a swap between nums[r] = 0 and nums[i] = 2, we should
        // not increment the i pointer as that might lead 0 in the middle of the array leaving the
        // array unsorted.

        int l = 0, r = nums.size()-1;
        int i = 0;
        while(i <= r){
            if(nums[i] == 0){
                swap(nums[i], nums[l]);
                l++;
            }else if(nums[i] == 2){
                swap(nums[i], nums[r]);
                r--;
                i--;
            }
            i++;
        }
    }
};
// @lc code=end

