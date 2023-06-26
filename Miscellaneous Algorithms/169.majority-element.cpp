/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // We use the Moore's voting algorithm here where the majority element is
        // guaranteed to be appearing at least in half of the size of the entire array.
        // Whenever any element is encountered, it does two things, either it increases
        // its own count, or it cancels the count of some other element.

        int cnt = 0, res = 0;
        for(int &x: nums){
            if(cnt == 0){
                cnt = 1;
                res = x;
            }
            else
                cnt += (x == res)?1:-1;
        }
        return res;
    }
};
// @lc code=end

