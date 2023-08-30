/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        long long low = 1, high = piles.back(), res = 0;
        while (low <= high) {
            long long m = low + (high - low) / 2;
            if (canEat(piles, m, h)) {
                res = m;
                high = m - 1;
            } else {
                low = m + 1;
            }
        }
        return res;
    }

   private:
    bool canEat(vector<int>& piles, int k, int h) {
        long long hCnt = 0, currentVal = 0;
        for (int i = 0; i < piles.size(); i++) {
            currentVal = piles[i];
            hCnt += currentVal / k + bool(currentVal % k);
        }
        return hCnt <= h;
    }
};
// @lc code=end
