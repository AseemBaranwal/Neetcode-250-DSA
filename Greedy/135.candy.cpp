/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        // Do a left pass and a right pass, left pass initializes the minimum 
        // value for each child, right pass sets the correct value for each child.
        int n = ratings.size();
        vector<int> distribution(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i - 1])
                distribution[i] = distribution[i - 1] + 1;
        }
        for(int i = n-2; i >= 0; i--){
            if(ratings[i+1] < ratings[i])
                distribution[i] = max(distribution[i], distribution[i + 1]+1);
        }
        return accumulate(distribution.begin(), distribution.end(), 0);
    }
};
// @lc code=end

