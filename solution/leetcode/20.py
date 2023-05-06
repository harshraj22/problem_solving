# https://leetcode.com/problems/valid-parentheses/


class Solution:
    
    def isValid(self, s: str) -> bool:
        stack = []
        opening = list('({[')
        closing = list(')}]')
        
        for ch in s:
            if ch in opening:
                stack.append(ch)
            else:
                index = closing.index(ch)
                if not stack:
                    return False
                elif stack[-1] != opening[index]:
                    return False
                stack.pop()
        return len(stack) == 0
