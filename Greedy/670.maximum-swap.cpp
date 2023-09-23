/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int maximumSwap(int num) {
        vector<int> integers;
        while (num > 0) {
            integers.push_back(num % 10);
            num /= 10;
        }
        reverse(integers.begin(), integers.end());
        vector<int> nextBig(integers.size());
        int idx = integers.size() - 2;
        nextBig[idx + 1] = -1;
        int mxIdx = idx + 1;
        while (idx >= 0) {
            if (integers[idx] < integers[mxIdx]) {
                nextBig[idx] = mxIdx;
            } else {
                nextBig[idx] = idx;
                mxIdx = idx;
            }
            idx--;
        }
        for (int i = 0; i < integers.size(); i++) {
            if (integers[nextBig[i]] > integers[i]) {
                swap(integers[i], integers[nextBig[i]]);
                break;
            }
        }
        int res = 0;
        for (int i = 0; i < integers.size(); i++) {
            res *= 10;
            res += integers[i];
        }
        return res;
    }
};
// @lc code=end

int main() { cout << Solution().maximumSwap(98368) << endl; }