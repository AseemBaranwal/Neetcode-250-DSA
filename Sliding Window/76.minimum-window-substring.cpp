/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        // Keep on increasing the right pointer till you reach a situation where
        // all characters are contained inside. Once you reach this point, start
        // changing and moving your left pointer, and each time mininize your
        // string size. NOTE POINT: Only store the indices when getting values,
        // and calculate the string towards the end for higher performance else
        // MLE.
        if (s.size() < t.size()) return "";
        int l = 0;
        unordered_map<char, int> mp1;
        pair<int, int> val;
        for (char &ch : t) mp1[ch]++;
        bool found = false;
        int remChCnt = mp1.size(), resSize = s.size() + 1;
        for (int r = 0; r < s.size(); r++) {
            if (mp1.count(s[r])) {
                mp1[s[r]]--;
                if (mp1[s[r]] == 0) remChCnt--;
            }
            while (remChCnt == 0) {
                found = true;
                int cSize = r - l + 1;
                if (cSize < resSize) {
                    val.first = l, val.second = r;
                    resSize = cSize;
                }
                if (mp1.count(s[l])) {
                    mp1[s[l]]++;
                    if (mp1[s[l]] == 1) remChCnt++;
                }
                l++;
            }
        }
        return found ? s.substr(val.first, val.second - val.first + 1) : "";
    }
};
// @lc code=end

int main() {
    string s1 = "a", s2 = "a";
    cout << Solution().minWindow(s1, s2) << endl;
    s1 = "a", s2 = "aa";
    cout << Solution().minWindow(s1, s2) << endl;
    return 0;
}

/*            r
s = "ADOBECODEBANC", t = "ABC"
mp1['A'] = 0, mp['B'] = -1, mp['C'] = 0;
remChCnt = 0
res = "ADOBEC"
resSize = 6
cSize = 6
*/