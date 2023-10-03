/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        // Sort the clips so as to find an increasing sequence.Further,
        // run a loop until the currentEnd is covered inside the interval.
        // If even after this, the value wasn't increased, it means that there
        // is a clip breakage at the value currEnd + 1. In such a case, we
        // return -1.
        sort(clips.begin(), clips.end());
        int i = 0, currEnd = 0, clipCount = 0;
        while (currEnd < time) {
            int newEnd = currEnd;
            while (i < clips.size() and clips[i][0] <= currEnd) {
                newEnd = max(newEnd, clips[i][1]);
                i++;
            }
            if (newEnd == currEnd) return -1;
            currEnd = newEnd;
            clipCount++;
        }
        return clipCount;
    }
};
// @lc code=end
