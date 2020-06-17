Problem: 
   - [Day 17](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3363/)

Tried: 
   - Simple `DFS` of `Flood Fill algo`


```c++
class Solution {
	int n, m;

	void replace(vector<vector<char>> &board, char strt, char final) {
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < m; j += 1) {
				if (board[i][j] == strt)
					board[i][j] = final;
			}
		}
	}

	bool isValid(int x, int y) {
		if (x < 0 || y < 0) return false;
		else if (x >= n || y >= m) return false;
		return true;
	}

	void flood_fill(vector<vector<char>> &board, int x, int y, char ch) {
		if (!isValid(x, y)) return;
		else if (board[x][y] != 'O')
			return;
		board[x][y] = ch;
		flood_fill(board, x-1, y, ch);
		flood_fill(board, x+1, y, ch);
		flood_fill(board, x, y-1, ch);
		flood_fill(board, x, y+1, ch);
	}

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
		n = board.size();
		m = board[0].size();

		// mark all '0' that are reachable to border
		for (int col = 0; col < m; col += 1) {
			if (board[0][col] == 'O')
				flood_fill(board, 0, col, '#');
			if (board[n-1][col] == 'O')
				flood_fill(board, n-1, col, '#');
		} 

		for (int row = 0; row < n; row += 1) {
			if (board[row][0] == 'O')
				flood_fill(board, row, 0, '#');
			if (board[row][m-1] == 'O')
				flood_fill(board, row, m-1, '#');
		}

		// the unmarked '0' are surrounded by 'X' and
		// thus need to be replaced
		replace(board, 'O', 'X');

		// unmark the remaining 'O'
		replace(board, '#', 'O');
    }
};
```