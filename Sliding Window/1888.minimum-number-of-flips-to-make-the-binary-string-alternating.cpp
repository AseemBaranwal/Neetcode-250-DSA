/*
 * @lc app=leetcode id=1888 lang=cpp
 *
 * [1888] Minimum Number of Flips to Make the Binary String Alternating
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int minFlips(string s) {
        // Refer to the Neetcode Solution
        // General Idea: There are only two strings possible to compare with -
        // both alternating with 0s and 1s We don't need to compare each value
        // again and again as it still remains the same in the newly generated
        // string after operation type-1 We have duplicated the strings to make
        // sure that strings are equivalent and each sliding window can be seen.
        int size = s.size();
        s += s;
        string cmp1, cmp2;
        for (int i = 0; i < size * 2; i++) {
            cmp1 += (i & 1) ? "0" : "1";
            cmp2 += (i & 1) ? "1" : "0";
        }
        int diff1 = 0, diff2 = 0;
        int res = size;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            diff1 += (cmp1[r] == s[r] ? 0 : 1);
            diff2 += (cmp2[r] == s[r] ? 0 : 1);
            if (r - l + 1 > size) {
                diff1 -= (cmp1[l] == s[l] ? 0 : 1);
                diff2 -= (cmp2[l] == s[l] ? 0 : 1);
                l++;
            }
            if (r - l + 1 == size) {
                res = min(res, min(diff1, diff2));
            }
        }
        return res;
    }
};
// @lc code=end

int main() {
    string s1 = "010";
    string s2 = "01001001101";
    cout << Solution().minFlips(s1) << endl;
    cout << Solution().minFlips(s2) << endl;
}