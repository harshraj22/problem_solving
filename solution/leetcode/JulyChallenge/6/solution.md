Problem: 
   - [Day 6](https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3383/)

Tried: 
   - Simple `DFS`


```c++
class Solution {
    int n, m, edge;

    void dfs(int x, int y, vector<vector<int>> &grid, int &perim) {
        perim += 4;
        grid[x][y] = 0;

        if (x+1 < n && grid[x+1][y] == 1) 
            perim -= edge;
        if (x-1 >= 0 && grid[x-1][y] == 1) 
            perim -= edge;
        if (y+1 < m && grid[x][y+1] == 1) 
            perim -= edge;
        if (y-1 >= 0 && grid[x][y-1] == 1) 
            perim -= edge;
        
        if (x+1 < n && grid[x+1][y] == 1) 
            dfs(x+1, y, grid, perim);
        if (x-1 >= 0 && grid[x-1][y] == 1) 
            dfs(x-1, y, grid, perim);
        if (y+1 < m && grid[x][y+1] == 1) 
            dfs(x, y+1, grid, perim);
        if (y-1 >= 0 && grid[x][y-1] == 1) 
            dfs(x, y-1, grid, perim);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perim = 0; n = grid.size(), m = grid[0].size();
        edge = 2;

        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (grid[i][j] == 1)
                    dfs(i, j, grid, perim);
            }
        }
        
        return perim;
    }
};
```
