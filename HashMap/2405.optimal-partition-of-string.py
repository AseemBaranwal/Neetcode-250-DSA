#
# @lc app=leetcode id=2405 lang=python3
#
# [2405] Optimal Partition of String
#

# @lc code=start
class Solution:
    def partitionString(self, s: str) -> int:
        d = dict()
        unique_count = 0
        for ch in s:
            if ch in d:
                unique_count += 1
                d = dict()
                d[ch] = 1
            else:
                d[ch] = 1
        return unique_count+1
        
# @lc code=end

