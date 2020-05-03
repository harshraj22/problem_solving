Problem: 
   - [Day 3](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/)

Tried: 
   - Use of `Counter` from `collections`
   - Counter1 - Counter2 returns a counter object having only keys whose values are positive
   - Counter.subtract(Counter) does in-place subtraction of counter objects
   - Read more about various other counter operations [here](https://docs.python.org/3/library/collections.html#collections.Counter.subtract)

```python
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        from collections import Counter
        
        magazine_char_freq = Counter(magazine)
        ransomNote_char_freq = Counter(ransomNote)
        
        magazine_char_freq.subtract(ransomNote)
        
        if any(freq < 0 for freq in magazine_char_freq.values()):
            return False
        return True
```