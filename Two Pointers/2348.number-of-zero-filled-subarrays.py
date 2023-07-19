#
# @lc app=leetcode id=2348 lang=python3
#
# [2348] Number of Zero-Filled Subarrays
#

from typing import List

# @lc code=start
class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        count = 0
        curr_count = 0
        for val in nums:
            if val == 0:
                curr_count += 1
            else:
                count += curr_count**2 - (curr_count + 1)*curr_count/2 + curr_count
                curr_count = 0
        count += curr_count**2 - (curr_count + 1)*curr_count/2 + curr_count
        return int(count)
        
# @lc code=end

