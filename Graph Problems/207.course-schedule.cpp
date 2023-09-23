/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build a graph (directed) and then add the inDegrees. Use a queue to
        // initialize the graph with nodes having indegrees equal to 0. Keep on
        // removing edges by decrementing in degrees and add to the queue when
        // the in degrees drop to zero.
        graph G = buildGraph(numCourses, prerequisites);
        queue<int> Q;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) Q.push(i);
        }
        while (!Q.empty()) {
            int currNode = Q.front();
            Q.pop();
            numCourses--;
            for (int child : G[currNode]) {
                in[child]--;
                if (in[child] == 0) {
                    Q.push(child);
                }
            }
        }
        return numCourses == 0;
    }

   private:
    typedef vector<vector<int>> graph;
    int in[2005];
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph G(numCourses);
        memset(in, 0, sizeof(in));
        for (vector<int>& v : prerequisites) {
            G[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        return G;
    }
};
// @lc code=end
