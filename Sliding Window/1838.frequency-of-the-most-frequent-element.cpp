/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        // Keep in mind that if we keep track of an average from left to right,
        // we just need to check if the average is >= maxElement. Since we don't
        // want a subarray, we can sort thr elements and the max element will be
        // the at the right in window
        sort(nums.begin(), nums.end());
        long long subSum = 0;
        int res = 0, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            subSum += nums[r];
            while ((long long)(subSum + k) / (r - l + 1) < nums[r]) {
                subSum -= nums[l];
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 4, 8, 13};
    cout << s.maxFrequency(nums, 5) << endl;
    return 0;
}
// @lc code=end
