// https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> next(n, vector<int>(m, 0));
        auto isValid = [&](int i, int j)->bool{
            if (i < 0 || j < 0)
                return false;
            else if (i >= n || j >= m)
                return false;
            return true;
        };
        
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                // for each cell
                int sum = 0;
                for (int ii = -1; ii < 2; ii += 1) {
                    for (int jj = -1; jj < 2; jj += 1) {
                        if (ii || jj) {
                            int x = i + ii, y = j + jj;
                            if (isValid(x, y))
                                sum += board[x][y];
                        }
                    }
                }

                // current cell is alive
                if (board[i][j] == 1) {
                    if (sum < 2)
                        next[i][j] = 0;
                    else if (sum < 4)
                        next[i][j] = 1;
                    else 
                        next[i][j] = 0;
                }
                else 
                    next[i][j] = (sum == 3);
            }
        }

        board = next;
    }
};

/* 
1: Live, 2: Dead
Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

*/