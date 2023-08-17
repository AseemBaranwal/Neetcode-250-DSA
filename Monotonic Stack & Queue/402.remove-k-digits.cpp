/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    string removeKdigits(string &num, int k) {
        // Pay attention that this problem is similar to sliding window maximum.
        // We maintain a small increasing deque and push values such that
        // resultant string size is n-k, hence the sliding window size required
        // is k+1
        deque<int> dq;
        int i = 0, n = num.size();
        string res;
        while (i < n) {
            while (!dq.empty() and num[dq.back()] > num[i]) dq.pop_back();
            dq.push_back(i);
            if (i + 1 >= k + 1) {
                res += num[dq.front()];
                dq.pop_front();
            }
            i++;
        }
        int zeroCnt = 0;
        for (int i = 0; i < res.size() and res[i] == '0'; i++) zeroCnt++;
        if (zeroCnt == res.size())
            res = "0";
        else
            res = res.substr(zeroCnt);
        return res;
    }
};
// @lc code=end
