# https://leetcode.com/problems/partition-equal-subset-sum/description/

from functools import lru_cache

class Solution:
    def __init__(self):
        self.nums = None

    @lru_cache(None)
    def get(self, index, target):
        if index >= len(self.nums):
            return target == 0
        elif target < 0:
            return False
        return self.get(index+1, target) or self.get(index+1, target - self.nums[index])

    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2 == 1:
            return False
        target = sum(nums) / 2
        self.nums = nums

        return self.get(0, target)

