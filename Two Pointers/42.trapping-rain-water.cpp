/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include <bitset>/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int trap(vector<int>& height) {
        // Water can be trapped only when we have a peak in the left or the
        // right direction. If we have a peek in either direction, take out the
        // minimum of both of them and the current height is subtracted to get
        // the total amount of water trapped.
        // Use a rightMax variable and leftMax array to keep track of the
        // maximum and keep updating right max and add to res

        vector<int> leftMax(height.size());
        leftMax[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        int rightMax = 0;
        long res = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            rightMax = max(height[i], rightMax);
            res += min(leftMax[i], rightMax) - height[i];
        }
        return res;
    }
};
// @lc code=end
