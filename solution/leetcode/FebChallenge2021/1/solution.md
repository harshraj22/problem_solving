Problem:
   - [Day1](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3625/)

Tried:
   - Convert int to binary string

``` python
class Solution:
    def hammingWeight(self, n: int) -> int:
        s = bin(n)[2:]
        return s.count('1')
        
```