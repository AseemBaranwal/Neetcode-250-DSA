/*
 * @lc app=leetcode id=1343 lang=cpp
 *
 * [1343] Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 */

#include <bitset>/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0, r = 0;
        long cSum = 0, subarrayCnt = 0;
        while(r < arr.size()) {
            if(r-l < k-1){
                cSum += arr[r];
                r++;
                continue;
            }
            cSum += arr[r++];
            if(threshold <= cSum/k) subarrayCnt++;
            cSum -= arr[l++];
        }
        return subarrayCnt;
    }
};
// @lc code=end

