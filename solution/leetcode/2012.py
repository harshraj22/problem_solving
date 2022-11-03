# https://leetcode.com/problems/sum-of-beauty-in-the-array/

class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        left_max = [nums[0] for _ in nums]
        right_min = [nums[-1] for _ in nums]

        for index, num in enumerate(nums[1:], 1):
            left_max[index] = max(num, left_max[index-1])
        
        n = len(nums)
        for index in range(n-2, -1, -1):
            right_min[index] = min(nums[index], right_min[index+1])

        ans = 0
        for i in range(1, n-1):
            if left_max[i-1] < nums[i] < right_min[i+1]:
                ans += 2
            elif nums[i-1] < nums[i] < nums[i+1]:
                ans += 1
                
        return ans
