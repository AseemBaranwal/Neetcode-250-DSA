#
# @lc app=leetcode id=2001 lang=python3
#
# [2001] Number of Pairs of Interchangeable Rectangles
#

from typing import List
import math

# @lc code=start
class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        # Pay attention that besides using the ratio, we should prefer to use the pairs as
        # the hash keys reason being that precision can't be good for keys when hashed.
        pair_count = {}
        for rect in rectangles:
            gcd_num = math.gcd(rect[0], rect[1])
            lst = (rect[0]//gcd_num, rect[1]//gcd_num)
            if lst in pair_count:
                pair_count[lst] += 1
            else:
                pair_count[lst] = 1
        res = 0
        for ratio in pair_count.keys():
            res += math.comb(pair_count[ratio], 2)
        return res
    
# @lc code=end

