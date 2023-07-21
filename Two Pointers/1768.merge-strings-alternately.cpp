/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string res;
        while(i < word1.size() and j < word2.size()){
            res += word1[i++] ;
            res += word2[j++];
        }
        res += word1.substr(i) + word2.substr(j);
        return res;
    }
};
// @lc code=end

