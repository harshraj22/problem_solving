# https://leetcode.com/problems/jump-game-vi/

from sortedcontainers import SortedList


class Solution:
    from math import inf
    
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        scores = [nums[-1] for _ in nums]
        window = SortedList([(nums[-1], n-1)])
        
        for i in range(n-2, -1, -1):
            cur_score = nums[i] + window[-1][0]
            if i + k < n:
                window.discard((scores[i+k], i+k))
            scores[i] = cur_score
            window.add((scores[i], i))

        return scores[0]
