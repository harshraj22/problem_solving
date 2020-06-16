# https://leetcode.com/problems/generate-parentheses/submissions/
# Simple Dynamic Programming
# My Refactored solution

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return []
        
        dp = [None for i in range(10**6+1)]
        dp[0], dp[1] = [''], ['()']
        
        def solve_for(n):
            if dp[n] is not None:
                return dp[n]
            dp[n] = []
            for i in range(n):
                prefix, suffix = solve_for(i), solve_for(n-1-i)
                dp[n].extend(['(' + left + ')' + right for left in prefix for right in suffix])
                        
            return dp[n]
        
        return solve_for(n)
        

class Solution:
    def generateParenthesis(self, n: int, open=0, closed=0, s='') -> List[str]:
        if closed > open:
            return []
        elif closed == n:
            return [s]
        elif open == n:
            return [s + ')'*(n-closed)]
        return self.generateParenthesis(n, open+1, closed, s+'(') + self.generateParenthesis(n, open, closed+1, s+')')


'''
# My original solution
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return []
        elif n == 1:
            return ['()']
        
        dp = [None for i in range(10**6+1)]
        dp[0] = ['']
        dp[1] = ['()']
        
        def recur(n):
            if dp[n] is not None:
                return dp[n]
            # dp[n] = ['(' + recur(i) + ')' + recur(n-i-1) for i in range(n)]
            dp[n] = []
            for i in range(n):
                first, last = recur(i), recur(n-1-i)
                for left in first:
                    for right in last:
                        dp[n].append('(' + left + ')' + right)
                        
            return dp[n]
        
        return recur(n)
        
'''