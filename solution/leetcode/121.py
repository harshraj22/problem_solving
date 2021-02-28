# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# solved again on Feb28, 2021

class Solution:
    from math import inf 
    
    def maxProfit(self, prices: List[int]) -> int:
        n, min_so_far, max_profit = len(prices), inf, 0
        dp = [[0 for _ in prices] for __ in [1, 2]]
        
        # dp[0], dp[1] = buy, sell
        for index, price in enumerate(prices):
            dp[0][index], dp[1][index] = -price, price - min_so_far
            min_so_far = min(min_so_far, price)
            max_profit = max(max_profit, dp[1][index])
            
        return max_profit