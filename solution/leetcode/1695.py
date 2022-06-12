# https://leetcode.com/problems/maximum-erasure-value/

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        window = set()
        cur_sum, best_sum = 0, 0
        left, right = 0, 0
        
        while right < len(nums):
            while nums[right] in window:
                window.discard(nums[left])
                cur_sum -= nums[left]
                left += 1
            
            cur_sum += nums[right]
            window.add(nums[right])
        
            best_sum = max(best_sum, cur_sum)
            right += 1
            
        return best_sum
            
