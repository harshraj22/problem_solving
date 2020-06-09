// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0
// Used Flood Fill Algo

#include<bits/stdc++.h>
using namespace std;

int n, m;

bool isValid(int x, int y) {
    if (x < 0 || y < 0) return false;
    else if (x >= n || y >= m) return false;
    return true;
}

int flood_fill(vector<vector<int>> &matrix, int x, int y, int &sz) {
    if (!isValid(x, y)) return 0;
    else if (matrix[x][y] == 0) return 0;
    matrix[x][y] = 0;   sz += 1;
    for (int i = -1; i < 2; i += 1) {
        for (int j = -1; j < 2; j += 1)
            flood_fill(matrix, x+i, y+j, sz);
    }

    return sz;
}

void solve() {
    int components = 0, num = 0;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int> (m));
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1)
            cin >> matrix[i][j];
    }

    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            if (matrix[i][j] == 1) {
                components = 0;
                num = max(num, flood_fill(matrix, i, j, components));
            }
        }
    }

    cout << num << '\n';
}

int main() {
    int test;   cin >> test;
    while (test--)
        solve();

    return 0;
}

