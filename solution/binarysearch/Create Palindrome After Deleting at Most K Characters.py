# https://binarysearch.com/problems/Create-Palindrome-After-Deleting-at-Most-K-Characters

class Solution:
    def __init__(self):
        self.dp = [[]]

    def initialize(self, n, k):
        # dp.shape: (k x n)
        self.dp = [[None for _ in range(n)] for _ in range(k)]

    def get(self, left, right, s):
        # return min num of chars reqired to be deleted to convert s[left:right-left+1] into a palindrome
        if right <= left:
            return 0
        elif self.dp[left][right] != None:
            return self.dp[left][right]
        if s[left] == s[right]:
            self.dp[left][right] = self.get(left+1, right-1, s)
        else:
            self.dp[left][right] = min(self.get(left+1, right, s) + 1, self.get(left, right-1, s) + 1)

        return self.dp[left][right]

    def solve(self, s, k):
        n = len(s)
        self.initialize(n, n)

        return self.get(0, n-1, s) <= k
