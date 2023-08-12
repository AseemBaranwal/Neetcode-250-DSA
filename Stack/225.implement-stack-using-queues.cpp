/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class MyStack {
   public:
    // Pop is not possible in O(1) time, hence every single time you push
    // elements, push in the opposite order and then extract values out of it.
    MyStack() {}
    queue<int> Q;

    void push(int x) {
        Q.push(x);
        for (int i = 0; i < Q.size() - 1; i++) {
            Q.push(Q.front());
            Q.pop();
        }
    }

    int pop() {
        int val = Q.front();
        Q.pop();
        return val;
    }

    int top() { return Q.front(); }

    bool empty() { return Q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
