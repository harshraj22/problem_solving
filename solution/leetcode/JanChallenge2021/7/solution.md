Problem:
   - [Day7](https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3595/)

Tried:
   - Linear Time, Two pointers, Single Pass
   - Space: O(num of diff chars)

``` python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest, left, chars = 0, 0, set()

        for right, char in enumerate(s):
            while char in chars:
                chars.discard(s[left])
                left += 1
            chars.add(char)
            longest = max(longest, len(chars))

        return longest
```