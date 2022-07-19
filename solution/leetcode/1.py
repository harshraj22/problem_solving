# https://leetcode.com/problems/two-sum/


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for first_index, first_num in enumerate(nums):
            for second_index, second_num in enumerate(nums[first_index+1:], first_index+1):
                if first_num + second_num == target:
                    return [first_index, second_index]
        
        raise Exception(f'Wrong input data. Expected sum of atleast two numbers to be {target}')


""" 
class Solution:
    from collections import Counter
    
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        indexes = {num: index for index, num in enumerate(nums)}
        counts = Counter(nums)
        
        for index, num in enumerate(nums):
            residual = target - num
            if residual not in indexes:
                continue
            if residual != num:
                return [index, indexes[residual]]
            elif counts[residual] > 1:
                return [index, indexes[residual]]

"""