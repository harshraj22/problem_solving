// https://leetcode.com/problems/cherry-pickup-ii/
// Idea from editorial
// dp[row][col1][col2]: max profit starting from 'row'th row when robots are at:
//          (row, col1) and (row, col2)

class Solution {
    int dp[101][101][101];
    vector<vector<int>> matrix;
    vector<int> dirs;
    int N, inf;

    int recur(int row, int col1, int col2) {
        // max profit when robots are at: (row, col1), (row, col2)
        if (row >= matrix.size()) return 0;
        else if (min(col1, col2) < 0) return -inf;
        else if (max(col1, col2) >= matrix[0].size()) return -inf;
        else if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int cur = matrix[row][col1] + (col1 != col2)*matrix[row][col2];
        for (auto i: dirs) {
            for (auto j: dirs) 
                dp[row][col1][col2] = max(dp[row][col1][col2], recur(row+1, col1+i, col2+j));
        }

        dp[row][col1][col2] += cur;
        return dp[row][col1][col2];
    }

public:
    Solution() {
        N = 101;
        for (int i = 0; i < N; i += 1) {
            for (int j = 0; j < N; j += 1) {
                for (int k = 0; k < N; k += 1)
                    dp[i][j][k] = -1;
            }
        }

        inf = 1e6;
        dirs = {-1, 0, 1};
    }

    int cherryPickup(vector<vector<int>>& grid) {
        matrix = grid;
        int n = matrix[0].size();
        return recur(0, 0, n-1);
    }
};