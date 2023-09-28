/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        unordered_map<string, vector<string>> G;
        for (int i = 0; i < bank.size(); i++) {
            for (int j = i + 1; j < bank.size(); j++) {
                bool singleChange = changeOne(bank[i], bank[j]);
                if (singleChange) {
                    G[bank[i]].push_back(bank[j]);
                    G[bank[j]].push_back(bank[i]);
                }
            }
            if (changeOne(bank[i], startGene)) {
                G[bank[i]].push_back(startGene);
                G[startGene].push_back(bank[i]);
            }
        }
        queue<string> Q;
        Q.push(startGene);
        int intermediateMutations = 0;
        unordered_set<string> vis;
        while (!Q.empty()) {
            int k = Q.size();
            for (int i = 0; i < k; i++) {
                string curr = Q.front();
                Q.pop();
                if (curr == endGene) return intermediateMutations;
                vis.insert(curr);
                for (string &ass : G[curr]) {
                    if (vis.find(ass) == vis.end()) {
                        Q.push(ass);
                    }
                }
            }
            intermediateMutations++;
        }
        return -1;
    }

   private:
    inline bool changeOne(string &a, string &b) {
        int k = a.size(), diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i])
                continue;
            else {
                if (diff)
                    return false;
                else
                    diff = 1;
            }
        }
        return diff == 1;
    }
};
// @lc code=end
