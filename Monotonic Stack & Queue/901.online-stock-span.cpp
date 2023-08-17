/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class StockSpanner {
   public:
    StockSpanner() {}
    stack<pair<int, int>> st;
    int counter = 1;

    int next(int price) {
        while (!st.empty() and price >= st.top().first) st.pop();
        int res = counter;
        if (!st.empty()) res = counter - st.top().second;
        st.push({price, counter});
        counter++;
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
