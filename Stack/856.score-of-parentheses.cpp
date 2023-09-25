/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;
        for (char &ch : s) {
            if (ch == '(') {
                st.push(score);
                score = 0;
            } else {
                int currentScore = st.top();
                int previousDoubledScore = max(2 * score, 1);
                score = currentScore + previousDoubledScore;
                st.pop();
            }
        }
        return score;
    }
};
// @lc code=end
