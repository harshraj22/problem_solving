# https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/794/

class Solution:
    def generateParenthesis(self, n: int, open=0, closed=0, s='') -> List[str]:
        if closed > open:
            return []
        elif closed == n:
            return [s]
        elif open == n:
            return [s + ')'*(n-closed)]
        return self.generateParenthesis(n, open+1, closed, s+'(') + self.generateParenthesis(n, open, closed+1, s+')')
