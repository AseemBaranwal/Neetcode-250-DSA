/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, r = accumulate(weights.begin(), weights.end(), 0);
        int res = INT_MAX;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (feasible(weights, m, days))
                r = m - 1, res = min(res, m);
            else
                l = m + 1;
        }
        return res;
    }

   private:
    bool feasible(vector<int>& weights, int capacity, int days) {
        int dayCnt = 1, currentVal = 0;
        for (int i = 0; i < weights.size(); i++) {
            currentVal += weights[i];
            if (currentVal > capacity) {
                dayCnt++;
                currentVal = weights[i];
                if (currentVal > capacity) return false;
            }
        }
        return dayCnt <= days;
    }
};
// @lc code=end
