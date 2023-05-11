# https://leetcode.com/problems/longest-common-subsequence/ 

from functools import lru_cache

class Solution:
    
    @lru_cache(None)
    def get(self, s1, s2, n, m):
        if min(n, m) < 0:
            return 0
        if s1[n] != s2[m]:
            return max(self.get(s1, s2, n-1, m), self.get(s1, s2, n, m-1))

        return max(
            1+ self.get(s1, s2, n-1, m-1),
            self.get(s1, s2, n-1, m),
            self.get(s1, s2, n, m-1)
        )
        
    
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        return self.get(text1, text2, len(text1)-1, len(text2)-1)
