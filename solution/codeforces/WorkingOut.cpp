// https://codeforces.com/problemset/problem/429/B
// Simple multi-dimentional dp

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int matrix[n+2][m+2], sum[n+2][m+2][4];

    for (int i = 0; i <= n+1; i += 1) {
        for (int j = 0; j <= m+1; j += 1) {
            matrix[i][j] = 0;
            for (int k = 0; k < 4; k += 1)
                sum[i][j][k] = 0;
        }
    }

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1)
            cin >> matrix[i][j];
    }

    // sum[i][j][0]: from (1,1) to (i,j)
    // sum[i][j][1]: from (i,j) to (n,m)
    // sum[i][j][2]: from (n,1) to (i,j)
    // sum[i][j][3]: from (i,j) to (1,m)

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            sum[i][j][0] = matrix[i][j] + max(sum[i-1][j][0], sum[i][j-1][0]);
        }
    }

    for (int i = 1; i <= n; i += 1) {
        for (int j = m; j > 0; j -= 1) {
            sum[i][j][3] = matrix[i][j] + max(sum[i-1][j][3], sum[i][j+1][3]);
        }
    }

    for (int i = n; i > 0; i -= 1) {
        for (int j = 1; j <= m; j += 1) {
            sum[i][j][2] = matrix[i][j] + max(sum[i][j-1][2], sum[i+1][j][2]);
        }
    }

    for (int i = n; i > 0; i -= 1) {
        for (int j = m; j > 0; j -= 1) {
            sum[i][j][1] = matrix[i][j] + max(sum[i+1][j][1], sum[i][j+1][1]);
        }
    }

    int ans = 0;
    for (int i = 2; i < n; i += 1) {
        for (int j = 2; j < m; j += 1) {
            int come1 = sum[i][j-1][0] + sum[i+1][j][2];
            int come2 = sum[i-1][j][0] + sum[i+1][j][2];
            int come3 = sum[i-1][j][0] + sum[i][j-1][2];
            int go1 = sum[i][j+1][1] + sum[i-1][j][3];
            int go2 = sum[i+1][j][1] + sum[i-1][j][3];
            int go3 = sum[i+1][j][1] + sum[i][j+1][3];
            
            int curAns = max({come1+go1, come3+go3});
            ans = max(ans, curAns);
        }
    }

    cout << ans << '\n';

    return 0;
}