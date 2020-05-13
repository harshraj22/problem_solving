# https://leetcode.com/problems/house-robber/submissions/
# Another simple DP

class Solution:
    def rob(self, cost: List[int]) -> int:
        if len(cost) < 3:
            return max(cost) if cost else 0
        
        # dp[0][i] = profit when not rob i'th house
        dp = [[0 for _ in cost] for __ in [1, 2]]
        dp[1][:2], dp[0][1] = cost[:2], cost[0]

        for index, val in enumerate(cost[2:], 2):
            dp[0][index] = max(dp[0][index-1], dp[1][index-1])
            dp[1][index] = val + max(dp[0][index-2], dp[1][index-2])

        return max(dp[0][-1], dp[1][-1])