/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // For every single edge, before inserting it into the graph, we check if it can already be
        // reachable from some other node. If it is possible, it means, the new edge that we are
        // joining will lead to a cycle. If it can't be reachable, then it is added to the graph
        vector<int> lastRedundantEdge(2);
        for(auto edge: edges) {
            fill(vis.begin(), vis.end(), 0);
            int firstNode = edge[0], secondNode = edge[1];
            dfs(firstNode);
            if(!vis[secondNode]){
                G[firstNode].push_back(secondNode);
                G[secondNode].push_back(firstNode);
            }else{
                lastRedundantEdge = edge;
            }
        }
        return lastRedundantEdge;
    }
private:
    vector<vector<int>> G = vector<vector<int>>(1005);
    vector<bool> vis = vector<bool>(1005);
    void dfs(int node){
        vis[node] = 1;
        for(int neighbour: G[node]){
            if(!vis[neighbour]){
                dfs(neighbour);
            }
        }
    }
};
// @lc code=end

