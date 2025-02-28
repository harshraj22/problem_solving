# https://leetcode.com/problems/sliding-window-maximum/description/


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        stack, ans = [], []
        # initialize the monotonic stack (index, val)
        # the largest is present at the earliest
        for index, num in enumerate(nums[:k]):
            self.addToStack(stack, index, num)
        
        ans.append(stack[0][1])
        for index, num in enumerate(nums[k:], k):
            if stack[0][0] <= index-k:
                stack = stack[1:]
            self.addToStack(stack, index, num)
            ans.append(stack[0][1])
        
        return ans

    def addToStack(self, stack, index, num):
        while stack and stack[-1][1] <= num:
            stack.pop()
        if not stack or stack[-1][1] > num:
            stack.append((index, num))
        
