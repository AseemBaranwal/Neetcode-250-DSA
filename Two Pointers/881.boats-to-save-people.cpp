/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        // We can use Greedy as optimal solution has always first element and
        // some element for at least 2. Exception: each value > limit
        sort(people.begin(), people.end());
        int boatCount = 0;
        int start = 0, end = people.size() - 1;
        while (start <= end) {
            if (people[start] + people[end] <= limit)
                start++, end--, boatCount++;
            else
                end--, boatCount++;
        }
        return boatCount;
    }
};
// @lc code=end
