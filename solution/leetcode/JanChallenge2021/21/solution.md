Problem:
   - [Day21](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3611/)

Tried:
   - stack based concept to find next greater number
   - Help from editorial

``` python
class Solution:
  def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
    from collections import deque
    stack = []

    for index, num in enumerate(nums):
      if not stack or num >= stack[-1]:
        stack.append(num)
      else:
        while stack and len(stack) + (len(nums) - index) > k and stack[-1] > num:
          stack.pop()
        stack.append(num)
    return stack[:k]
```