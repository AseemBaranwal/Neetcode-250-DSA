#
# @lc app=leetcode id=28 lang=python3
#
# [28] Find the Index of the First Occurrence in a String
#

from typing import List

# @lc code=start
class Solution:
    def prepareLPS(self, string: str) -> List:
        res = [0 for _ in range(len(string))]
        j = 0; i = 1
        while i < len(string):
            if string[i] == string[j]:
                res[i] = j+1
                j += 1
            else:
                if j == 0:
                    res[i] = 0
                else:
                    j = res[j-1]
                    i -= 1
            i += 1
        return res

    def strStr(self, haystack: str, needle: str)  -> int:
        # We use KMP Algorithm to implement this. We create a Longest prefix suffix (LPS) 
        # Array and use it to get a complexity of O(M+N). Make sure that we use a different
        # string for the comparison because we always use the prefix.
        # Good testcase - "aabaaabaaac", "aabaaac"
        j = 0 # used for pointing the needle string
        lps = self.prepareLPS(needle)
        need = "*" + needle
        for i in range(len(haystack)):
            if j+1 < len(need) and haystack[i] == need[j+1]:
                j += 1
            else:
                while j > 0 and need[j+1] != haystack[i]:
                    j = lps[j-1]
                if haystack[i] == need[j+1]:
                    j += 1
            if j+1 == len(need):
                return i - j + 1
        return -1
# @lc code=end

