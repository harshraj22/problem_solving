// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();

        auto isValid = [&](int i, int j)->bool{
            if (i < 0 || j < 0)
                return false;
            else if (i >= n || j >= m)
                return false;
            return true;
        };

        for (int row = 1; row < n; row += 1) {
            for (int col = 0; col < m; col += 1) {
                int var = A[row][col];
                A[row][col] = INT_MAX;
                for (auto x: {-1, 0, 1}) {
                    if (isValid(row-1, col+x))
                        A[row][col] = min(A[row][col], A[row-1][col+x]);
                }
                A[row][col] += var;
            }
        }

        return *min_element(A[n-1].begin(), A[n-1].end());
    }
};