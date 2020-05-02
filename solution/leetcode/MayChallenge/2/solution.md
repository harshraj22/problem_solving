Problem: 
   - [Day 2](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/)

Tried: 
   - Use of `dict` or `map`


```python
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        from collections import Counter
        freq = dict(Counter(S))
        return sum(freq.get(j, 0) for j in J)
```