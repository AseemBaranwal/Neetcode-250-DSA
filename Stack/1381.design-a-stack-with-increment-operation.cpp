/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class CustomStack {
   public:
    // The approach is to use another array that grows along with the stack
    // everytime a value is inserted. Whenever some value is required to be
    // popped, it is first incremented with the current increment value. We take
    // advantage of the fact that whatever is added to the value at kth index is
    // going to be added to all the indices before k
    CustomStack(int maxSize) { capacity = maxSize; }

    void push(int x) {
        if (st.size() == capacity) return;
        st.push_back(x);
        inc.push_back(0);
    }

    int pop() {
        int current_idx = st.size() - 1;
        if (current_idx < 0) return -1;
        if (current_idx > 0) inc[current_idx - 1] += inc[current_idx];
        int res = st.back() + inc[current_idx];
        st.pop_back();
        inc.pop_back();
        return res;
    }

    void increment(int k, int val) {
        k = min(k, (int)st.size()) - 1;
        if (k >= 0) inc[k] += val;
    }

   private:
    vector<int> st, inc;
    int capacity = 0;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end
