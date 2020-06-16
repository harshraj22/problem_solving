# https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/796/

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return []
        elif len(nums) == 1:
            return [nums, []]
        others = self.subsets(nums[1:])
        return [[nums[0]]+sub for sub in others] + others
        