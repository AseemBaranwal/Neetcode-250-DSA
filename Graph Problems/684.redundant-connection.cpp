/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<pair<int, int>, int> mp;
        int cnt = 0;
        vector<int> resEdge(2);
        for(auto &edge: edges){
            cnt++;
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        // Helper function finds the largest index which is part of a cycle and returns it
        solve(mp, INT_MIN, resEdge, edges[0][0], -1);
        // Reprocess this later
        for(auto &edge: edges){
            if(mp[{edge[0], edge[1]}] == 1){
                resEdge[0] = edge[0];
                resEdge[1] = edge[1];
            }
        }
        return resEdge;
    }
private:
    vector<vector<int>> G = vector<vector<int>> (1005);
    vector<int> vis = vector<int> (1005);
    bool solve(map<pair<int, int>, int> &mp, int resIdx, vector<int> &resEdge, int src, int par = -1){
        vis[src] = 1;
        bool cyclePresent;
        // We form a cycle when we try to visit a neighbour but find out that it has already been visited
        for(int neighbour: G[src]){
            cyclePresent = false;
            if(!vis[neighbour]){
                cyclePresent = cyclePresent or solve(mp, resIdx, resEdge, neighbour, src) ;
                if(cyclePresent){
                    pair<int, int> current;
                    current.first = src, current.second = neighbour;
                    mp[current] = 1;
                    mp[{current.second, current.first}] = 1;
                }
            }else if(neighbour == par){
                continue;
            }
            else{
                // Already visited Node and not par
                pair<int, int> current;
                current.first = src, current.second = neighbour;
                mp[current] = 1;
                mp[{current.second, current.first}] = 1;
                cyclePresent = 1;
            }
        }
        return false;
    }
};

// 1 --> 2 --> 3
/* dfs(1) --> dfs(2) --> dfs(3) --> dfs(4) --> dfs(5)

resEdge = [4,1], resIdx = 3
src = 1
par = -1
vis = [0, 1, 0,0,0, 0]
G = [
0: 
1: [2,4,5]
2: [1,2]
3: [2,4]
4: [3,1]
5: [1]
]
mp[1,2] = mp[2,1] = 0
mp[2,3] = mp[3,2] = 1
mp[3,4] = mp[4,3] = 2
mp[1,4] = mp[4,1] = 3
mp[1,5] = mp[5,1] = 4
*/
// @lc code=end

