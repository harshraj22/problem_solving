# https://leetcode.com/problems/split-array-largest-sum/description/

from typing import Tuple
from math import inf
from functools import lru_cache, cache

class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        ans, n = inf, len(nums)
        self.nums = nums
        self.prefix_sum = [nums[0] for _ in nums]

        if k == 1:
            return sum(nums)

        # calc prefix sum
        for i, num in enumerate(nums[1:], 1):
            self.prefix_sum[i] = self.prefix_sum[i-1] + num

        for i in range(1, n):
            smallest_sum, is_possible = self.get(i, k-1)
            if is_possible:
                ans = min(ans, max(smallest_sum, self.prefix_sum[i] - nums[i]))
        
        return ans

    @cache
    def get(self, index: int, k: int) -> Tuple[int, bool]:
        if k == 0:
            if index < len(self.nums):
                return inf, False
            else:
                return inf, True
        elif k == 1:
            return self.prefix_sum[-1] - self.prefix_sum[index-1], True
        
        elif k > len(self.nums) - index:
            return inf, False
        
        ans, possible = inf, False
        for i in range(index+1, len(self.nums)):
            cur_chunk = self.prefix_sum[i-1] - self.prefix_sum[index-1]
            if possible and cur_chunk >= ans: # ans won't be updated as all chunks will be bigger
                break
            smallest_sum, is_possible = self.get(i, k-1)
            if is_possible:
                ans = min(ans, max(smallest_sum, self.prefix_sum[i-1] - self.prefix_sum[index-1]))
                possible = True
        
        return ans, possible




