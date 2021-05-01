// https://binarysearch.com/problems/Largest-Square-Matrix-with-Same-Value

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int> (m, 0));
    auto inside = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    int mx = 1;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            dp[i][j] = 1;
            if (!inside(i-1, j-1))
                continue;
            else if (matrix[i][j] != matrix[i-1][j-1])
                continue;
            else if (matrix[i][j] != matrix[i-1][j])
                continue;
            else if (matrix[i][j] != matrix[i][j-1])
                continue;
            dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            mx = max(mx, dp[i][j]);
        }
    }

    return mx;
}