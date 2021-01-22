Problem:
   - [Day22](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3613/)

Tried:
   - Bruteforce solution

``` python
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if set(word1) != set(word2):
            return False
        from collections import Counter
        w1 = Counter(word1).values()
        w2 = Counter(word2).values()
        return sorted(w1) == sorted(w2)

```