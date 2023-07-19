/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCnt = 0;
        for(int &x: nums){
            if(x == 0) return 0;
            else if(x < 0) negCnt++;
        }
        return negCnt&1 ? -1: 1;
    }
};
// @lc code=end

