Problem: 
   - [Day 1](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/)

Tried: 
   - Simple `Brute Force`.


```python
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return any([word == word.upper(), word == word.lower(), word == word.capitalize()])
```
