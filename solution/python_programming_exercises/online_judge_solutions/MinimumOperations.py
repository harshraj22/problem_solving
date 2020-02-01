# https://practice.geeksforgeeks.org/problems/find-optimum-operation/0

from collections import defaultdict
from itertools import permutations, combinations
import sys

sys.setrecursionlimit(100000)

dp = []

def recur(i,n):
    if i == n:
        return 0
    elif i > n:
        return 10**12
    elif dp[i] != -1:
        return dp[i]
    dp[i] = 1 + min(recur(2*i,n), recur(i+1,n))
    return dp[i]

def solve():
    n = int(input().strip())
    print(1 + recur(1,n))

if __name__ == '__main__':
    test = int(input().strip())
    for _ in range(test):
        dp = [-1 for i in range(10**4+3)]
        solve()