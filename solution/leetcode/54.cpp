// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int> > &A) {
        if (A.empty()) return {};
        int n = A.size(), m = A[0].size(), cur_dir = 0;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<int> ans;

        pair<int, int> start = {0, 0};

        auto isValid = [&](int i, int j)->bool{
            if (i < 0 || j < 0)
                return false;
            else if (i >= n || j >= m)
                return false;
            return true;
        };

        while (vis[start.first][start.second] == false) {
            int x = start.first, y = start.second;
            vis[x][y] = true;  ans.push_back(A[x][y]);
            for (int i = cur_dir; i < cur_dir+4; i += 1) {
                pair<int, int> offset = dir[i%4];
                x = start.first + offset.first; y = start.second + offset.second;
                if (isValid(x, y) && !vis[x][y]) {
                    start = make_pair(x, y); cur_dir = i % 4;
                    break;
                }
            }
        }

        return ans;
    }

};


/*
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        n, m = len(matrix), len(matrix[0])
        order, position, index = [], (0, 0), 0
        isValid = lambda x, y: (0 <= x < n) and (0 <= y < m)

        while len(order) != n*m:
            x, y = position
            order.append(matrix[x][y])
            matrix[x][y] = None
            if not isValid(x+dirs[index][0], y+dirs[index][1]):
                index = (index + 1)%len(dirs)
            elif matrix[x+dirs[index][0]][y+dirs[index][1]] == None:
                index = (index + 1)%len(dirs)
            position = (x+dirs[index][0], y+dirs[index][1])

        return order
        
        
        
class Solution:
    def get(self, matrix, xl, xr, yt, yb):
        if xl > xr or yt > yb:
            return None
        for i in range(xl, xr+1):
            yield matrix[yt][i]
        for j in range(yt+1, yb+1):
            yield matrix[j][xr]
        if yb != yt: # else same row will be repeated
            for i in range(xr-1, xl-1, -1):
                yield matrix[yb][i]
        if xl != xr: # else same col will be repeated
            for j in range(yb-1, yt, -1):
                yield matrix[j][xl]
        yield from self.get(matrix, xl+1, xr-1, yt+1, yb-1)

    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        n, m = len(matrix), len(matrix[0])
        return list(self.get(matrix, 0, m-1, 0, n-1))


*/
