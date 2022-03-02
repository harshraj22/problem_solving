# https://leetcode.com/problems/is-subsequence/

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        s, t = iter(s), iter(t)
        for s_i in s:
            for t_i in t:
                if s_i == t_i: # start comparing s[i+1]
                    break
            else: # if t has been consumed completely
                return False
                    
        # if s is fully consumed, return True
        # else return False
        return True
