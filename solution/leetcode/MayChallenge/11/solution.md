Problem: 
   - [Day 11](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/)

Tried: 
   - Used `DFS` to fill the `connected components`

```c++
class Solution {
    int n, m;
    vector<pair<int, int>> dir;
    bool isValid(int i, int j) {
        if (i < 0 || j < 0)
            return false;
        else if (i >= n || j >= m)
            return false;
        return true;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size(), m = image[0].size();
        dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        dfs(sr, sc, -1, image);
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1) {
                image[i][j] = (image[i][j] == -1 ? newColor: image[i][j]);
            }
        }
        return image;
    }
    
    void dfs(int r, int c, int col, vector<vector<int>>& image) {
        if (!isValid(r, c))
            return;
        int cur = image[r][c];
        image[r][c] = col;
        for (auto it: dir) {
            int x = r + it.first, y = c + it.second;
            if (isValid(x,y) && image[x][y] == cur)
                dfs(x, y, col, image);
        }
        
    }
};
```