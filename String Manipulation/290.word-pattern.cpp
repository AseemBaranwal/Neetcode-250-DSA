/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ptos;
        unordered_map<string, char> stop;
        istringstream ss(s);
        string curr;
        int idx = 0;
        while(getline(ss, curr, ' ')){
            if(ptos.find(pattern[idx]) != ptos.end() and ptos[pattern[idx]] != curr) return false;
            if(stop.find(curr) != stop.end() and stop[curr] != pattern[idx]) return false;
            ptos[pattern[idx]] = curr;
            stop[curr] = pattern[idx];
            idx++;
        }
        return idx == pattern.size();
    }
};
// @lc code=end

