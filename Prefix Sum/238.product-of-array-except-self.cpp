/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Maintaining an array that keeps track of the leftProduct and using a rightProduct
        // variable for the right product along the way. Space: O(N)

        int n = nums.size();
        vector<int> leftProduct(n, 1);
        for(int i = 1; i < n; i++)
            leftProduct[i] = nums[i-1]*leftProduct[i-1];
        
        vector <int> res(n);
        int rightProduct = 1;
        for(int i = n-1; i >= 0; i--){
            res[i] = leftProduct[i] * rightProduct;
            rightProduct *= nums[i];
        }
        return res;
    }
};
// @lc code=end

