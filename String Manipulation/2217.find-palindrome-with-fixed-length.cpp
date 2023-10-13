/*
 * @lc app=leetcode id=2217 lang=cpp
 *
 * [2217] Find Palindrome With Fixed Length
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
#define ll long long
class Solution {
   public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<ll> result;
        ll start = intLength % 2 == 0 ? pow(10, intLength / 2 - 1)
                                      : pow(10, intLength / 2);
        for (int q : queries) {
            string s = to_string(start + q - 1);
            string palindrome = s;
            reverse(s.begin(), s.end());
            if (intLength % 2 == 0) {
                palindrome += s;
            } else {
                palindrome += s.substr(1);
            }

            // len of palindrome should be intLength, otherwise -1
            if (palindrome.size() == intLength)
                result.push_back(stoll(palindrome));
            else
                result.push_back(-1);
        }

        return result;
    }
};
// @lc code=end

int main() {
    vector<int> values{1, 2, 3, 4, 5, 90};
    auto val = Solution().kthPalindrome(values, 3);
    for (auto v : val) {
        cout << v << " ";
    }
    return 0;
}