/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Using a set to label each sequences start points and then will check the length
        // of the longest sequence by constantly traversing until they are available
        unordered_set<int> present;
        for(int &x: nums) present.insert(x);
        int maxSize = 0;
        for(int &x: nums) {
            int currentSize = 1;
            if(present.find(x-1) == present.end()){
                for(int num = x+1; present.find(num) != present.end(); num++){
                    currentSize++;
                }
            }
            maxSize = max(maxSize, currentSize);
        }
        return maxSize;
    }
};
// @lc code=end

