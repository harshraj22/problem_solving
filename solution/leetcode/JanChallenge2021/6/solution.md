Problem:
   - [Day6](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3594/)

Tried:
   - Linear Time, Constant Space, Single Pass

``` python
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        lastNum = 0

        for index, val in enumerate(arr):
            if k > val - lastNum - 1:
                k -= (val - lastNum - 1)
            else:
                return lastNum + k
            lastNum = val
        return arr[-1] + k

```