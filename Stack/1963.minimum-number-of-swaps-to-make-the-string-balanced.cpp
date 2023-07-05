/*
 * @lc app=leetcode id=1963 lang=cpp
 *
 * [1963] Minimum Number of Swaps to Make the String Balanced
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSwaps(string s) {
        // We try to see remove all the balanced parentheses and whatever is left will have
        // to be swapped and that is what we would do.
        int open = 0, swaps = 0;
        for(char &ch: s){
            if(ch == '[') open++;
            else if(ch == ']' and open == 0) swaps++;
            else if(ch == ']' and open > 0) open--;
        }
        return (swaps+1)/2;
    }
};
// @lc code=end

