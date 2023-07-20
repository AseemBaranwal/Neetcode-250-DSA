/*
 * @lc app=leetcode id=2306 lang=cpp
 *
 * [2306] Naming a Company
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // Store into different buckets based on the first character and then use
        // a set to push the suffixes. Now search for each word from set1 in set2.
        // Get the intersections which have common suffixes in two buckets. Remove
        // them and then get your answer.

        // Since there can be at most 26 characters prefix, complexity boils down to
        // O(26*26 * N).
        unordered_map<char, unordered_set<string>> group;
        for(string &str : ideas){
            string suffix = str.substr(1);
            group[str[0]].insert(suffix);
        }
        long long count = 0;
        for(auto &g1: group){
            for(auto &g2: group){
                if(g1.first == g2.first) continue;
                // Find what suffix in g1 are present in g2 as well
                long long intersect = 0;
                for(auto &g1Val: g1.second){
                    if(g2.second.find(g1Val) != g2.second.end()){
                        // Value is found
                        intersect ++;
                    }
                }
                count += (long long)(g1.second.size()-intersect)*(long long)(g2.second.size()-intersect);
            }
        }
        return count;
    }
};
// @lc code=end

