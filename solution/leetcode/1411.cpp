// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
// Either time limit is too strict, or the solution is too bad !

class Solution {
    long long int dp[5001][3][3][3];
    int mod, n;

    bool isValid(vector<int> &cur, vector<int> &next) {
        return true;
        if (next[0] == next[1] || next[1] == next[2])
            return false;
        for (int i = 0; i < 3; i += 1)
            if (cur[i] == next[i])
                return false;
        return true;
    }

    int recur(int row, int c0, int c1, int c2) {
        if (row == 1) 
            return (c0 != c1) && (c1 != c2);
        else if (c0 == c1 || c1 == c2)
            return 0;
        else if (dp[row][c0][c1][c2] != -1)
            return dp[row][c0][c1][c2];

        vector<int> cur = {c0, c1, c2};
        dp[row][c0][c1][c2] = 0;
        for (int i = 0; i < 3; i += 1) {
            if (c0 == i) continue;
            for (int j = 0; j < 3; j += 1) {
                if (c1 == j || i == j) continue;
                for (int k = 0; k < 3; k += 1) {
                    if (c2 == k || j == k) continue;
                    vector<int> next = {i, j, k};
                    if (isValid(cur, next)) {
                        dp[row][c0][c1][c2] += recur(row-1, i, j, k);
                        // dp[row][c0][c1][c2] %= mod;
                        while (dp[row][c0][c1][c2] >= mod)
                            dp[row][c0][c1][c2] -= mod;
                    }
                }
            }
        }

        return dp[row][c0][c1][c2];
    }

public:
    Solution() {
        mod = 1e9 + 7;
        for (int i = 0; i < 5001; i += 1) {
            for (int j = 0; j < 3; j += 1) {
                for (int k = 0; k < 3; k += 1) {
                    for (int l = 0; l < 3; l += 1)
                        dp[i][j][k][l] = -1;
                }
            }
        }        
    }

    int numOfWays(int n) {
        this->n = n;
        long long int sum = 0;
        for (int i = 0; i < 3; i += 1) {
            for (int j = 0; j < 3; j += 1) {
                if (i == j) continue;
                for (int k = 0; k < 3; k += 1) {
                    if (j == k) continue;
                    sum = (sum + recur(n, i, j, k));
                    while (sum >= mod) sum -= mod;
                }
            }
        }

        return sum;
    }
};