Problem:
   - [Day13](https://leetcode.com/explore/challenge/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3638/)

Tried:
   - BFS in grid

``` cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int inf = 1e6;
        vector<vector<int>> dist(n, vector<int> (m, inf));
        
        if (grid[0][0] == 1)
            return -1;

        auto inside = [&](int a, int b) {
            if (a < 0 || b < 0) return false;
            else if (a >= n || b >= m) return false;
            return true;
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 0;

        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();

            int x = temp.first, y = temp.second;
            vector<pair<int, int>> v = {{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}, {x-1, y-1}, {x-1, y+1}, {x+1, y-1}, {x+1, y+1}};

            for (auto a: v) {
                if (!inside(a.first, a.second))
                    continue;
                else if (grid[a.first][a.second] == 1)
                    continue;
                if (dist[a.first][a.second] > dist[x][y] + 1) {
                    dist[a.first][a.second] = dist[x][y] + 1;
                    q.push(a);
                }
            }
        }
        
        if (dist[n-1][m-1] == inf)
            dist[n-1][m-1] = -2;

        return dist[n-1][m-1] + 1;
    }
};
```