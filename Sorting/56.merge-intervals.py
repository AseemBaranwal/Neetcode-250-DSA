#
# @lc app=leetcode id=56 lang=python3
#
# [56] Merge Intervals
#

from typing import List

# @lc code=start
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        intervals.sort()
        start, end = intervals[0]
        for interval in intervals:
            if end < interval[0]:
                res.append([start, end])
                start, end = interval
            else:
                end = max(end, interval[1])
        res.append([start, end])
        return res
        
# @lc code=end

