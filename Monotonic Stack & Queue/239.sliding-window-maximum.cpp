// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Maintain a deque to keep track of the consecutive smallest values in
        // form of a monotonic queue Whenever a bigger value comes than last
        // value in deque, keep doing popback Append at the end.
        deque<int> dq;
        vector<int> res;
        for (int r = 0; r < nums.size(); r++) {
            if (!dq.empty() and dq.front() == r - k) dq.pop_front();
            while (!dq.empty() and nums[r] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(r);
            if (r + 1 >= k) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
// @lc code=end
