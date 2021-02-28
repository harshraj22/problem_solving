# https://leetcode.com/problems/min-cost-climbing-stairs/
# Simple Dynamic Programming based solution
# solved again on Feb28, 2021

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0 for _ in cost]
        dp[-1], dp[-2] = cost[-1], cost[-2]
        
        # iterate from end, with index
        for index, val in reversed(list(enumerate(cost[:-2]))):
            dp[index] = val + min(dp[index+1], dp[index+2])

        return min(dp[:2])