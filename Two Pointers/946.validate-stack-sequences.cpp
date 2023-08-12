/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // This is a simulation problem. Try to push elements and keep on
        // checking if the elements are popped out, if they are popped and equal
        // to value in popped, keep on popping them. Towards the end try to pop
        // all the values in the stack/array. If the resulting array after all
        // this is empty, we have a valid stack sequence.
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushed.size()) {
            st.push(pushed[i++]);
            while (!st.empty() and st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        while (!st.empty() and j < popped.size()) {
            if (st.top() != popped[j]) return false;
            st.pop();
            j++;
        }
        return st.empty() and j == popped.size();
    }
};
// @lc code=end
