# https://leetcode.com/problems/number-of-1-bits/description/

class Solution:
    def hammingWeight(self, n: int) -> int:
        print(bin(n)[2:], n)
        return bin(n)[2:].count('1')
