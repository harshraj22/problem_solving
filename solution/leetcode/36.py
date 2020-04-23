# https://leetcode.com/problems/valid-sudoku/
# basic implementation

class Solution:
    from collections import defaultdict
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        def check(row: List[str]) -> bool:
            # returns if the row is valid
            freq = defaultdict(lambda: 0)
            for num in row:
                if num != '.':
                    freq[num] += 1
                    
                    if freq[num] > 1:
                        return False
            return True
            
        
        # check rows
        for row in board:
            if not check(row):
                return False
        
        # check cols
        for col in range(9):
            row = [board[i][col] for i in range(9)]
            if not check(row):
                return False
        
        # check each 3 x 3
        for row in range(0, 9, 3):
            for col in range(0, 9, 3):
                cur = board[row][col: col+3]
                cur.extend(board[row+1][col: col+3])
                cur.extend(board[row+2][col: col+3])
                
                if not check(cur):
                    return False
                
        return True