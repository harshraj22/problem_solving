# https://leetcode.com/problems/climbing-stairs/
# Fibonachi based easy DP 

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0 for _ in range(n+1)]
        dp[1:3] = [1, 1]
        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]

        return dp[n]
