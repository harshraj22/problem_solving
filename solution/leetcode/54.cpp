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


*/