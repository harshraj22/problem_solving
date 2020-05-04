# https://leetcode.com/problems/surrounded-regions/

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board) == 0:
            return None
        n, m = len(board), len(board[0])
        
        isValid = lambda x, y: 0 <= x < n and 0 <= y < m

        def dfs(i, j):
            if not isValid(i, j) or board[i][j] != 'O':
                return None
            board[i][j] = 'y'
            for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                dfs(x, y)
        
        for j in range(m):
            [dfs(i, j) for i in [0, n-1]]
        
        for i in range(n):
            [dfs(i, j) for j in [0, m-1]]
                
        for i in range(n):
            for j in range(m):
                board[i][j] = 'O' if board[i][j] == 'y' else 'X'
