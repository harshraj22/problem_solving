Problem:
   - [Day25](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3616/)

Tried:
   - Linear time constant space, single pass

``` python
class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        from math import inf
        last = -inf
        for index, val in enumerate(nums):
            if val != 1:
                continue
            if index - last <= k:
                return False
            last = index
        return True
        
```