/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26);
        for(char &ch: text)
            cnt[ch-'a']++;
        int res = INT_MAX;
        for(int i = 0; i < cnt.size(); i++){
            if('a'+i == 'b' or 'a'+i == 'a' or 'a'+i == 'n')
                res = min(res, cnt[i]);
            else if('a'+i == 'l' or 'a'+i == 'o')
                res = min(res, cnt[i]/2);
        }
        return res;
    }
};
// @lc code=end

