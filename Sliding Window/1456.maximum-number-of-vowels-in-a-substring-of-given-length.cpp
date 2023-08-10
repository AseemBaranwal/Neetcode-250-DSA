/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int maxVowels(string s, int k) {
        // Jale p nama
        int l = 0, r = 0;
        int windowVowelCnt = 0, maxVowelCount = 0;
        while (r < s.size()) {
            while (r - l + 1 < k) {
                windowVowelCnt += isVowel(s[r]);
                r++;
            }
            windowVowelCnt += isVowel(s[r]);
            maxVowelCount = max(maxVowelCount, windowVowelCnt);
            windowVowelCnt -= isVowel(s[l]);
            l++;
            r++;
        }
        return maxVowelCount;
    }

   private:
    inline bool isVowel(char &ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
};

// @lc code=end

int main() {
    cout << Solution().maxVowels("aeiou", 2) << endl;
    cout << Solution().maxVowels("leetcode", 3) << endl;
}