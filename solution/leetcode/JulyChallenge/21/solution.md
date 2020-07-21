Problem: 
   - [Day 21](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3397/)

Tried: 
   - Simple `DFS`


```c++
class Solution {
    int n, m;
    
    bool exists(string& s, int index, int x, int y, vector<vector<char>> &board, vector<vector<bool>> &vis) {
        if (index == s.size())
            return true;
        else if (x < 0 || y < 0)
            return false;
        else if (x >= n || y >= m)
            return false;
        else if (board[x][y] != s[index])
            return false;
        else if (vis[x][y] == true)
            return false;
        
        // baord[x][y] = string[index]
        vis[x][y] = true;
        bool possible = false;
        
        // search for next char 
        if (!possible)
            possible |= exists(s, index+1, x+1, y, board, vis);
        if (!possible)
            possible |= exists(s, index+1, x-1, y, board, vis);
        if (!possible)
            possible |= exists(s, index+1, x, y+1, board, vis);
        if (!possible)
            possible |= exists(s, index+1, x, y-1, board, vis);
        
        vis[x][y] = false;
        return possible;        
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        // from each cell, try to check the string
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (exists(word, 0, i, j, board, vis))
                    return true;
            }
        }
        
        return false;
    }
};
```
