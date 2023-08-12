/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MinStack {
    // Implement a stack pair where at each value, store two things - the
    // current element and the minElement so far. At each push, update your
    // minElement
   public:
    stack<pair<int, int>> st;

    MinStack() {}

    void push(int val) {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
