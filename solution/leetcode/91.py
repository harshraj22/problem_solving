# https://leetcode.com/problems/decode-ways/description/

from functools import lru_cache

class Solution:
    def __init__(self):
        self.s = None
        self.mappings = dict()
        for index, val in enumerate('abcdefghijklmnopqrstuvwxyz', 1):
            self.mappings[str(index)] = val

    @lru_cache(None)
    def get(self, i):
        if i >= len(self.s):
            return 1
        elif self.s[i] == '0':
            return 0
        ans = self.get(i+1)
        if i+1 < len(self.s) and self.s[i:i+2] in self.mappings:
            ans += self.get(i+2)
        return ans

    def numDecodings(self, s: str) -> int:
        self.s = s
        return self.get(0)
