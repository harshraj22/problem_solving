# https://leetcode.com/problems/reverse-pairs/

from bisect import bisect_right as upper_bound

class Solution:
    def __init__(self):
        self.ans = 0
    
    def recur(self, nums):
        if len(nums) < 2: return nums
        
        mid = len(nums) // 2
        left, right = self.recur(nums[:mid]), self.recur(nums[mid:])
        
        for val in right:
            index = upper_bound(left, 2 * val)
            self.ans += len(left) - index
        
        return sorted(left + right)
    
    def reversePairs(self, nums: List[int]) -> int:
        if len(nums) < 2: return 0
        self.recur(nums)
        
        
        return self.ans
    