// https://leetcode.com/problems/number-of-closed-islands/
// Simple DFS based solution

class Solution {
    #define pi pair<int, int>
    
    int n, m, count;
    vector<pi> directions;
    
    bool isValid(int i, int j) {
        if (i < 0 || j < 0)
            return false;
        else if (i >= n || j >= m)
            return false;
        return true;
    }
    
    void dfs(int i, int j, vector<vector<int>> &grid) {
        if (!isValid(i, j))
            return;
        else if (grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        
        for (auto it: directions) {
            dfs(i+it.first, j+it.second, grid);
        }
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        
        directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        n = grid.size(), m = grid[0].size(), count = 0;
        
        for (int i = 0; i < n; i += 1) {
            dfs(i, 0, grid);  dfs(i, m-1, grid);
        }
        
        for (int j = 0; j < m; j += 1) {
            dfs(0, j, grid);  dfs(n-1, j, grid);
        }
        
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                if (grid[i][j] == 0) {
                    dfs(i, j, grid);
                    count += 1;
                }
            }
        }
        
        return count;
    }
};