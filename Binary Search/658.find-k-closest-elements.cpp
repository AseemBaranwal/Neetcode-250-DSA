/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // The idea is to find out the closest element to k and then travel in
        // both directions. Keep in mind that the lower_bound returns next
        // bigger value if not found, hence l = idx-1, r=idx covers all the
        // cases Sort the array and return
        vector<int> res;
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = idx - 1, r = idx;
        while (k > 0) {
            long long rightVal = (r < arr.size()) ? arr[r] : INT_MAX;
            long long leftVal = (l >= 0) ? arr[l] : INT_MIN;
            if (abs(rightVal - x) < abs(leftVal - x)) {
                res.push_back(arr[r]);
                r++;
            } else {
                res.push_back(arr[l]);
                l--;
            }
            k--;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
