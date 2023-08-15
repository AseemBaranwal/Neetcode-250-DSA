/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;
        for (int i = 0; i < position.size(); i++) {
            ps.push_back({position[i], speed[i]});
        }
        sort(ps.begin(), ps.end());
        int res = 1;
        float cTime = (float)(target - ps.back().first) / ps.back().second;
        int i = position.size() - 2;
        while (i >= 0) {
            if (cTime < (float)(target - ps[i].first) / ps[i].second) {
                res++;
                cTime = (float)(target - ps[i].first) / ps[i].second;
                i--;
            } else {
                while (i >= 0 and
                       cTime >= (float)(target - ps[i].first) / ps[i].second) {
                    i--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
