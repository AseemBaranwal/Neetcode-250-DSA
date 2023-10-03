/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> G;
        vector<int> vis(arr.size(), 0);
        int n = arr.size();
        for (int& ele : arr) G[ele].push_back(&ele - &arr[0]);
        queue<int> Q;
        Q.push(0);
        vis[0] = 1;
        int jumps = 0;
        while (!Q.empty()) {
            int k = Q.size();
            while (k--) {
                int curr = Q.front();
                Q.pop();
                if (curr == n - 1) return jumps;
                if (curr - 1 >= 0 and !vis[curr - 1])
                    Q.push(curr - 1), vis[curr - 1] = 1;
                if (curr + 1 < n and !vis[curr + 1])
                    Q.push(curr + 1), vis[curr + 1] = 1;
                for (int& idx : G[arr[curr]])
                    if (!vis[idx]) Q.push(idx), vis[idx] = 1;
                G[arr[curr]].clear();
            }
            jumps++;
        }
        return -1;
    }
};
// @lc code=end
