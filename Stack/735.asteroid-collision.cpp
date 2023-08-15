/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // After a collision has already occured, another collision with the
        // same asteroid won't occur
        vector<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            int as = asteroids[i];
            if (st.empty() or st.back() < 0 or as > 0)
                st.push_back(as);
            else if (as < 0 and st.back() <= -as) {
                if (st.back() < -as) i--;
                st.pop_back();
            }
        }
        return st;
    }
};
// @lc code=end
