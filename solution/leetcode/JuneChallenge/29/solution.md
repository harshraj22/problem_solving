Problem: 
   - [Day 29](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/543/week-5-june-29th-june-30th/3375/)

Tried: 
   - Simple `Dynamic Programming`

```c++
class Solution {
    bool isValid(int x, int y, int m, int n) {
        if (min(x, y) < 0) 
            return false;
        else if (x >= m || y >= n)
            return false;
        return true;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int> (n, 0));
        grid[0][0] = 1;

        for (int i = 0; i < grid.size(); i += 1) {
            for (int j = 0; j < grid[0].size(); j += 1) {
                if (isValid(i-1, j, m, n))
                    grid[i][j] += grid[i-1][j];
                if (isValid(i, j-1, m, n))
                    grid[i][j] += grid[i][j-1];
            }
        }

        return grid[m-1][n-1];
    }
};
```
