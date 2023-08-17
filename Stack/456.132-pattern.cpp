/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        // Try to maintain a minStack from the back, and whenever you get a
        // value which is lesser than the greatest value, you found your answer.
        // i < j < k is already guaranteed as we are traversing from right to
        // left.
        stack<int> st;
        int numsK = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int num = nums[i];
            if (numsK > num) return true;
            while (!st.empty() and st.top() < num) {
                numsK = st.top();
                st.pop();
            }
            st.push(num);
        }
        return false;
    }
};
// @lc code=end
