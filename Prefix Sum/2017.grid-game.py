#
# @lc app=leetcode id=2017 lang=python3
#
# [2017] Grid Game
#

from typing import List

# @lc code=start
class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        # Keep in mind that the goal is to minimize the robot 2 score and not maximize it
        prefixSumR1 = [0]*(len(grid[0]))
        prefixSumR2 = [0]*(len(grid[1]))

        prefixSumR1[0] = grid[0][0]
        prefixSumR2[0] = grid[1][0]

        for idx in range(1, len(grid[0])):
            prefixSumR1[idx] += prefixSumR1[idx-1] + grid[0][idx]
            prefixSumR2[idx] += prefixSumR2[idx-1] + grid[1][idx]
        
        res = float("inf")
        for i in range(len(grid[0])):
            top = prefixSumR1[-1] - prefixSumR1[i]
            bottom = prefixSumR2[i-1] if i > 0 else 0
            secondRobotPoints = max(top, bottom)
            res = min(res, secondRobotPoints)
        return res

# @lc code=end

