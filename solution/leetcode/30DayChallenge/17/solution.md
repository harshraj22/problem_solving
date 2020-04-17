Problem:
   - [Day17](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3302/)

Tried:
   - Simple `DFS` based solution
   - used `lambda functions`

``` c++
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        
        int n = grid.size(), m = grid[0].size(), count = 0;
        
        auto isValid = [&](int i, int j)->bool{
            if (i < 0 || j < 0)
                return false;
            else if (i >= n || j >= m)
                return false;
            return true;
        };
        
        function<void(int, int)> dfs = [&](int i, int j){
            if (!isValid(i, j))
                return;
            else if (grid[i][j] == '0')
                return;
            else 
                grid[i][j] = '0';
            
            dfs(i, j+1);
            dfs(i, j-1);
            dfs(i-1, j);
            dfs(i+1, j);            
        };
        
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    count += 1;
                }
            }
        }
        
        return count;
    }
};
```