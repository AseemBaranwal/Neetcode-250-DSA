/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
#define MOD 1000000007
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() -1;
        int res = 0, n = nums.size();
        vector<int> powerOfTwo(n,1);
        for(int i = 1; i < n; i++){
            powerOfTwo[i] = (powerOfTwo[i-1]*2)%MOD;
        }
        while(l <= r){
            int sum = nums[l] + nums[r];
            if(sum <= target){
                res = (res + powerOfTwo[r-l])%MOD;
                l++;
            }else
                r--;
        }
        return res;
    }
};
/*
l      r
[3,3,6,6,8]
2^3 = 8
[3], [3], [6]

         l r
[2,3,3,4,6,7]

2^5 + 2^4 + 2^3 + 2^2 + 2^0
32 + 16 + 8 + 4 + 1
*/
// @lc code=end

/*

    [3,5,6,7]

*/