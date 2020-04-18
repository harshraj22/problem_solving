Problem:
   - [Day18](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3303/)

Tried:
   - Basic `Dynamic Programming`

``` c++
class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || j < 0)
            return false;
        else if (i >= n || j >= m)
            return false;
        return true;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                int cur = grid[i][j];
                grid[i][j] = INT_MAX;
                if (isValid(i-1, j, n, m))
                    grid[i][j] = min(grid[i][j], cur + grid[i-1][j]);
                if (isValid(i, j-1, n, m))
                    grid[i][j] = min(grid[i][j], cur + grid[i][j-1]);
                if (grid[i][j] == INT_MAX)
                    grid[i][j] = cur;
            }
        }
        
        return grid[n-1][m-1];
    }
};
```