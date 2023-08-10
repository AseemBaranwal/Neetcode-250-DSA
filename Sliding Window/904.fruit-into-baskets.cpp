/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int totalFruit(vector<int> &fruits) {
        // You can't sort - Read the problem
        // Keep Track of the last time a basket is used and keep on replacing
        // the value whenever you reach out of the bounds.
        int res = 0;
        int l = 0;
        int lastIdxB1 = -1, lastIdxB2 = -1;
        for (int r = 0; r < fruits.size(); r++) {
            if (lastIdxB1 == -1 or fruits[lastIdxB1] == fruits[r])
                lastIdxB1 = r;
            else if (lastIdxB2 == -1 or fruits[lastIdxB2] == fruits[r])
                lastIdxB2 = r;
            else {
                if (lastIdxB1 > lastIdxB2) {
                    l = lastIdxB2 + 1;
                    lastIdxB2 = r;
                } else {
                    l = lastIdxB1 + 1;
                    lastIdxB1 = r;
                }
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end
