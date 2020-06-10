Question [Link](https://leetcode.com/problems/unique-paths/)

Time: O(n * m) <br>
Space: O(n * m)

Idea Used: Iterative Dynamic Programming. #path from (i, j) = #path from (i+1, j) + #path from (i, j+1)

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        swap(n, m);
        vector<vector<int>> grid(n+1, vector<int> (m+1, 0));
        // he can move down or right
        grid[n-1][m-1] = 1;
        for (int i = n-1; i >= 0; i -= 1) {
            for (int j = m-1; j >= 0; j -= 1) {
                grid[i][j] += (grid[i+1][j] + grid[i][j+1]);
            }
        }

        return grid[0][0];
    }
};
```