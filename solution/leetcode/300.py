# https://leetcode.com/problems/longest-increasing-subsequence/description/

from math import inf
from bisect import bisect_left


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [inf for _ in nums] + [inf]
        for num in nums:
            index = bisect_left(dp, num)
            if dp[index] >= num:
                dp[index] = num
            else:
                dp[index+1] = min(dp[index+1], num)
        
        for index, val in enumerate(dp):
            if dp[index+1] == inf:
                return index+1
