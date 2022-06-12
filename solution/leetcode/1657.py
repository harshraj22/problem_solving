# https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        from collections import Counter
        
        if set(word1) != set(word2):
            return False
        
        c1 = list(Counter(word1).values())
        c2 = list(Counter(word2).values())
        
        return sorted(c1) == sorted(c2)
