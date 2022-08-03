# https://leetcode.com/problems/edit-distance/

class Solution:
    from functools import lru_cache
    
    @lru_cache
    def edit(self, i, j):
        if i == len(self.w1):
            return len(self.w2) - j
        elif j == len(self.w2):
            return len(self.w1) - i
        if self.w1[i] == self.w2[j]:
            return self.edit(i+1, j+1)
        else:
            return 1 + min(self.edit(i+1, j), self.edit(i, j+1), self.edit(i+1, j+1))
        
    def minDistance(self, word1: str, word2: str) -> int:
        self.w1 = word1
        self.w2 = word2
        return self.edit(0, 0)