/*
 * @lc app=leetcode id=2115 lang=cpp
 *
 * [2115] Find All Possible Recipes from Given Supplies
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        // kahn's algorithm. Treat every node as the ingredient or the recipe
        // name
        unordered_map<string, vector<string>> G;
        unordered_map<string, int> inDegree;
        for (int i = 0; i < recipes.size(); i++) {
            for (int j = 0; j < ingredients[i].size(); j++) {
                G[ingredients[i][j]].push_back(recipes[i]);
                inDegree[recipes[i]]++;
            }
        }
        queue<string> Q;
        unordered_map<string, bool> present;
        for (string& supply : supplies) {
            Q.push(supply);
        }

        while (!Q.empty()) {
            string curr = Q.front();
            Q.pop();
            present[curr] = 1;
            for (auto& recipe : G[curr]) {
                if (!present[recipe]) {
                    inDegree[recipe]--;
                    if (inDegree[recipe] == 0) {
                        Q.push(recipe);
                    }
                }
            }
        }
        vector<string> res;
        for (string& recipe : recipes) {
            if (present[recipe]) {
                res.push_back(recipe);
            }
        }
        return res;
    }
};
// @lc code=end
