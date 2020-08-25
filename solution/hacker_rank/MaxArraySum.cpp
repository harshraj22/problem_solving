// https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming
// Simple DP
// Time: O(n) Space: O(n) can be improved to O(1)

int maxSubsetSum(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> dp(2, vector<int>(n, 0));

    // dp[0][i]: i'th is not included
    dp[1][0] = arr[0];

    for (int i = 1; i < n; i += 1) {
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        dp[1][i] = arr[i] + dp[0][i-1];
    }

    return max(dp[0][n-1], dp[1][n-1]);
}
