/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        graph G = buildGraph(numCourses, prerequisites);
        queue<int> Q;
        for (int i = 0; i < numCourses; i++)
            if (in[i] == 0) Q.push(i);

        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            numCourses--;
            order.push_back(curr);
            for (int child : G[curr]) {
                in[child]--;
                if (in[child] == 0) Q.push(child);
            }
        }
        return numCourses == 0 ? order : vector<int>();
    }

   private:
    typedef vector<vector<int>> graph;
    int in[2005];
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        memset(in, 0, sizeof(in));
        graph G(numCourses);
        for (vector<int>& v : prerequisites) {
            G[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        return G;
    }
};
// @lc code=end
