/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // The idea is to consider every element as the middle from the beginning and find
        // instances of all characters to the both ends and then check if both sides have the
        // characters without considering the one in the middle. The good thing is that we
        // need just one character on each side considering the size of subsequence = 3
        unordered_set<string> unique_palindromes;
        unordered_set<char> left;
        unordered_map<char, int> right;
        for(char &ch: s) right[ch]++;
        for(int i = 0; i < s.size() - 1; i++){
            right[s[i]]--;
            for(int j = 0; j < 26; j++){
                char ch = 'a' + j;
                if(left.find(ch) != left.end() and right[ch] > 0){
                    string curr = string(1,ch);
                    curr += s[i];
                    curr += ch;
                    unique_palindromes.insert(curr);
                }
            }
            left.insert(s[i]);
        }
        return unique_palindromes.size();
    }
};
// @lc code=end

