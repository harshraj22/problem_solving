// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0

#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
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


int main() {
    int test;   cin >> test;
    while (test--) {
        int n, m;   cin >> n >> m;
        vector<vector<int>> v(n, vector<int> (m));
        for (auto &it: v) {
            for (auto &i: it)
                cin >> i;
        }
        for (auto i: spiralOrder(v))
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}