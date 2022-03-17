# https://leetcode.com/problems/restore-the-array/

class Solution:
    from itertools import islice
    
    def numberOfArrays(self, s: str, k: int) -> int:
        mod = 10**9 + 7
        dp = [0 for _ in s]
        n = len(s)
        dp[-1] = int(0 < int(s[-1]) <= k)
        
        for i in range(n-2, -1, -1):
            val = 0
            # for j, ch in enumerate(islice(s, i, len(s)), i):
            for j in range(i, len(s)):
                ch = s[j]
                val = val * 10 + int(ch)
                if val > k or val == 0:
                    break
                if j+1 < len(s):
                    dp[i] = (dp[i] + dp[j+1])
            else:
                if 0 < val <= k:
                    dp[i] = (dp[i] + 1) 
                
        return dp[0] % mod
                
            
            
