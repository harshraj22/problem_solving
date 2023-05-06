# https://leetcode.com/problems/valid-palindrome/description/

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        alphabets = 'abcdefghijklmnopqrstuvwxyz0123456789'

        s = ''.join([ch for ch in s if ch in alphabets])
        print(s)
        return list(s) == list(reversed(s))
