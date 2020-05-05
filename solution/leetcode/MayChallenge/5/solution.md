Problem: 
   - [Day 5](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/)

Tried: 
   - Simple use of `Dictonary` of `Hash Map`

```python
class Solution:
    def firstUniqChar(self, s: str) -> int:
        from collections import Counter
        freq, n = Counter(s), len(s)
        
        for index, ch in enumerate(s):
            if freq[ch] == 1:
                return index
                
        return -1
```