# https://leetcode.com/problems/palindrome-partitioning-ii/description/

from collections import defaultdict
from functools import lru_cache, cache

import sys
sys.setrecursionlimit(4_000_020) 

class Solution:
    def minCut(self, s: str) -> int:
        self.s = s
        ans = max(0, len(s)-1)
        return min(ans, self.getCut(0))

    def getNextIndex(self, i) -> int:
        """Returns the next index after the current palindrome starting at index i"""

        for j in range(i, len(self.s)):
            if self.isPalindrome(i, j):
                yield j

    @lru_cache(maxsize=2_010)
    def getCut(self, i) -> int:
        """Returns min num of cut required for the string s[i:]"""

        if len(self.s[i:]) == 1 or i >= len(self.s):
            return 0
        elif self.isPalindrome(i, len(self.s)-1):
            return 0
        ans = len(self.s)-i-1
        for j in self.getNextIndex(i):
            ans = min(ans, 1 + self.getCut(j+1))
        return ans

    @cache
    def isPalindrome(self, i, j) -> bool:
        """Returns if the string s[i:j+1] is a palindrome"""

        if i == j:
            return True
        elif i+1 == j:
            return self.s[i] == self.s[j]
        elif self.s[i] != self.s[j]:
            return False
        return self.isPalindrome(i+1, j-1)
