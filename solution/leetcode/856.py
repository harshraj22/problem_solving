# https://leetcode.com/problems/score-of-parentheses/


class Solution:
    def prune(self, stack):
        if len(stack) < 2:
            return
        elif isinstance(stack[-1], int) and isinstance(stack[-2], int):
            stack[-2] += stack[-1]
            stack.pop()
            self.prune(stack)
        elif len(stack) >= 3 and (stack[-3], stack[-1]) == ('(', ')'):
            stack[-3] = stack[-2] * 2
            stack.pop()
            stack.pop()
            self.prune(stack)
    
    def scoreOfParentheses(self, s: str) -> int:
        _stack = []
        
        for ch in s:
            if ch == '(':
                _stack.append(ch)
            elif _stack[-1] == '(':
                _stack[-1] = 1
            else:
                _stack.append(ch)
            self.prune(_stack)
        
        return _stack[0]
