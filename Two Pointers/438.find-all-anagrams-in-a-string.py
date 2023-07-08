#
# @lc app=leetcode id=438 lang=python3
#
# [438] Find All Anagrams in a String
#

from typing import List
import collections

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        d = collections.Counter(p)
        j = 0
        res = []
        for i, ch in enumerate(s):
            # Shorten the sliding Window when the size crosses
            if i-j >= len(p):
                if s[j] in d:
                    d[s[j]] += 1
                j += 1
            # Adding the chracter to dictionary
            if ch in d:
                d[ch] -= 1
            flag = True
            for val in d.keys():
                if d[val] != 0:
                    flag = False
                    break
            if flag:
                res.append(j)
        return res
# @lc code=end

