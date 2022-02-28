# https://leetcode.com/problems/number-of-visible-people-in-a-queue/


class Solution:
    from collections import deque
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        _count = [0 for _ in heights]
        n = len(heights)
        _stack = deque([heights[-1]])
        
        for i in range(n-2, -1, -1):
            while _stack and heights[i] > _stack[0]:
                _stack.popleft()
                _count[i] += 1
            _count[i] += len(_stack) != 0
            _stack.appendleft(heights[i])
        return _count
