/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int calPoints(vector<string>& operations) {
        vector<int> points;
        for (string& op : operations) {
            if (op == "+") {
                int newScore = points.back() + points.at(points.size() - 2);
                points.push_back(newScore);
            } else if (op == "D") {
                points.push_back(points.back() * 2);
            } else if (op == "C") {
                points.pop_back();
            } else {
                points.push_back(stoi(op));
            }
        }
        return accumulate(points.begin(), points.end(), 0);
    }
};
// @lc code=end
