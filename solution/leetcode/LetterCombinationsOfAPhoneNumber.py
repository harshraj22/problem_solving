# https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/793/
# Backtracking based solution

class Solution:
    def __init__(self):
        self.letters = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'kjl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        elif len(digits) == 1:
            return list(self.letters[digits[0]])
        words = self.letterCombinations(digits[1:])
        return [ch+word for ch in self.letters[digits[0]] for word in words]        
