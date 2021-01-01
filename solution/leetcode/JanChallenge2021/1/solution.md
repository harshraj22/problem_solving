Problem:
   - [Day1](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3589/)

Tried:
   - Simple Recursive Bruteforce solution
   - Can be probably solved using Trie, as all nums are distinct

``` python
class Solution:
    def canFormArray(self, arr: List[int], pieces: List[List[int]]) -> bool:
        if not arr:
            return True

        for piece in pieces:
            n = len(piece)
            if n <= len(arr) and arr[:n] == piece:
                return self.canFormArray(arr[n:], pieces)

        return False
```