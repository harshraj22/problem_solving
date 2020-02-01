# https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

from collections import defaultdict
from itertools import permutations, combinations

dp,s,n = [[]], 'test', 0

def pre(n):
    '''
        fill dp table as -1
    '''
    global dp
    dp = [[-1 for j in range(n+1)] for i in range(n+1)]

def recur(left, right):
    '''
        returns if string[left:right+1] is palindrome
    '''
    if left == right:
        dp[left][right] = True
        return True
    elif left + 1 == right:
        dp[left][right] = True if s[left] == s[right] else False
        return dp[left][right]
    elif dp[left][right] != -1:
        return dp[left][right]
    elif s[left] != s[right]:
        recur(left+1,right)
        recur(left,right-1)
        dp[left][right] = False
        return False
    else:
        recur(left+1,right)
        recur(left,right-1)
        dp[left][right] = recur(left+1,right-1)
        return dp[left][right]
    
def solve():
    global s,n
    s = input().strip()
    n = len(s)
    pre(n)

    recur(0,n-1)
    ans,index = 0,None
    for i in range(n):
        for j in range(i,n):
            if dp[i][j] and ans < j-i+1:
                ans = j-i+1
                index = i
    print(s[index:index+ans])
    # print(dp)
    # for row in dp:
    #     print(row)


if __name__ == '__main__':
    test = int(input().strip())
    for _ in range(test):
        solve()