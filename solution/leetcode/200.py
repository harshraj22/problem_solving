# https://leetcode.com/problems/number-of-islands/

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0
        n, m, islands = len(grid), len(grid[0]), 0
        
        visited = [[False for _ in grid[0]] for __ in grid]
        isValid = lambda x, y: 0 <= x < n and 0 <= y < m
        
        def dfs(x, y):
            if not isValid(x, y) or grid[x][y] == '0':
                return 0
            grid[x][y] = '0'
            for i, j in [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]:
                dfs(i, j)
            return 1

        for i in range(n):
                islands += sum(dfs(i, j) for j in range(m))
            
        return islands

'''
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
'''