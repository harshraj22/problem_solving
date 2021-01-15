Problem:
   - [Day15](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3605/)

Tried:
   - simple implementation

``` python
class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        nums = [0 for _ in range(2*n+3)]
        nums[:2] = [0, 1]

        for i in range(n+1):
            if 2 <= 2*i <= n:
                nums[2*i] = nums[i]
            if 2 <= 2*i + 1 <= n:
                nums[2*i+1] = nums[i] + nums[i+1]

        return max(nums[:n+1])

```