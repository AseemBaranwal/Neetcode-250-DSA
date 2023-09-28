/*
 * @lc app=leetcode id=1366 lang=cpp
 *
 * [1366] Rank Teams by Votes
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    string rankTeams(vector<string>& votes) {
        // Store in such a way that posFreq[i][j] stores the number of times a
        // character i occurs at position j. Sort this and the resultant value
        // will be a sorted rows based on columns.
        if (votes.size() == 1) return votes[0];
        vector<vector<int>> posFreq(26, vector<int>(27, 0));
        // To create position part at the end whene everything is similar
        for (char& ch : votes[0]) {
            posFreq[ch - 'A'][26] = ch;
        }
        for (string& vote : votes) {
            for (int i = 0; i < vote.size(); i++) {
                --posFreq[vote[i] - 'A'][i];
            }
        }
        sort(posFreq.begin(), posFreq.end());
        string res;
        for (int i = 0; i < votes[0].size(); i++) {
            res += posFreq[i][26];
        }
        return res;
    }
};
// @lc code=end
