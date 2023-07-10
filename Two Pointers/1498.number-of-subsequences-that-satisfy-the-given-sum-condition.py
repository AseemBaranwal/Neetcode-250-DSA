#
# @lc app=leetcode id=1498 lang=python3
#
# [1498] Number of Subsequences That Satisfy the Given Sum Condition
#

from typing import List

# @lc code=start
MOD = 10**9 + 7
class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = 0
        l = 0; r = len(nums) - 1
        while l <= r:
            mnVal = nums[l]
            mxVal = nums[r]
            if mnVal + mxVal <= target:
                res = (res + (2**(r - l) % MOD)) % MOD
                l += 1
            else:
                r -= 1
        return res

# @lc code=end
