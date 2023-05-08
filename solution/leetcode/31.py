# https://leetcode.com/problems/next-permutation/description/

from bisect import bisect_right

class Solution:
    def get_next_larger(self, num, visited):
        visited.sort()
        index = bisect_right(visited, num)
        if index >= len(visited):
            return None, index
        return visited[index], index


    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if nums == sorted(nums, reverse=True):
            nums[:] = nums[::-1]
            return
        
        visited = [nums[-1]]
        n = len(nums)

        for i in range(n-2, -1, -1):
            num = nums[i]
            next, next_index = self.get_next_larger(num, visited)
            if next:
                nums[i] = next
                visited[next_index] = num

                nums[i+1:] = sorted(visited)
                return 
            visited.append(num)
