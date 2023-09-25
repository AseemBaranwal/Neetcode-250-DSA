/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        // Make sure that we are implementing a BFS on bus routes and not stops.
        // Hence push all the values of stops with curresponding buses taken
        // together and remove them from array to prevent them from getting
        // traversed again. In every iteration, all the stops at routes will be
        // traversed and accounted the same bus taken value and then pushed to
        // the queue.
        unordered_set<int> vis;
        unordered_map<int, vector<int>> G;
        for (int i = 0; i < routes.size(); i++) {
            for (int j : routes[i]) G[j].push_back(i);
        }
        queue<pair<int, int>> Q;
        Q.push({source, 0});
        vis.insert(source);
        while (!Q.empty()) {
            int currStop = Q.front().first, busCnt = Q.front().second;
            Q.pop();
            if (currStop == target) return busCnt;
            for (int busRoute : G[currStop]) {
                for (int stop : routes[busRoute]) {
                    if (vis.find(stop) == vis.end()) {
                        vis.insert(stop);
                        Q.push({stop, busCnt + 1});
                    }
                }
                routes[busRoute].clear();
            }
        }
        return -1;
    }
};
// @lc code=end
