/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // Use prefix sum to find out the gaps and based on count of these gaps, find out the
        // level (in the x direction) having the least number of gaps.
        unordered_map<int, int> gaps;
        for(int i = 0; i < wall.size(); i++){
            int prefix = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                prefix += wall[i][j];
                gaps[prefix]++;
            }
        }
        int x = 0, res = 0;
        for(auto pp: gaps){
            res = max(res, pp.second);
        }
        return wall.size() - res;
    }
};
// @lc code=end

