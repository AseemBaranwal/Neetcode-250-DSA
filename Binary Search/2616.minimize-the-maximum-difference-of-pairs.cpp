/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = 1e9, res = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(nums, p, mid)) {
                res = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return res;
    }

   private:
    bool possible(vector<int>& nums, int p, int val) {
        int cntFound = 0, idx = 0;
        while (cntFound < p and idx + 1 < nums.size()) {
            if (nums[idx + 1] - nums[idx] <= val) {
                cntFound++;
                idx += 2;
            } else
                idx++;
        }
        return cntFound == p;
    }
};
// @lc code=end

int main() {
    vector<int> v{10, 1, 2, 7, 1, 3};
    cout << Solution().minimizeMax(v, 2) << endl;
}