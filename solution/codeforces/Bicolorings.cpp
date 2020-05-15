// https://codeforces.com/problemset/problem/1051/D
// Similar to standard `tiling problem`

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

const int mod = 998244353;
ll n, k;
ll diffInCol(ll k, ll n);

const int N = 2e3+2;
vector<vector<int>> same(N, vector<int> (N, -1)), diff(N, vector<int> (N, -1));

ll sameInCol(ll k, ll n) {
    // Same color in the column
    // @k: number of components
    // @n: number of cells

    // termination condition
    if (k <= 0 || n <= 0)
        return 0;
    else if (n == 1) {
        return (k == 1) ? 2: 0;
    }

    else if (same[k][n] != -1)
        return same[k][n];

    return same[k][n] = (sameInCol(k-1, n-1) + 2*diffInCol(k, n-1) + sameInCol(k, n-1)) % mod;
}

ll diffInCol(ll k, ll n) {
    // Diff color in the column
    // @k: number of components
    // @n: number of cells

    // termination condition
    if (k <= 0 || n <= 0)
        return 0;
    else if (n == 1) {
        return (k == 2) ? 2: 0;
    }
    else if (diff[k][n] != -1)
        return diff[k][n];

    return diff[k][n] = (2*sameInCol(k-1, n-1) + diffInCol(k-2, n-1) + diffInCol(k, n-1)) % mod;
}

void solve(){
    cin >> n >> k;
    cout << (sameInCol(k, n) + diffInCol(k, n)) % mod << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    int test = 1;
    // cin >> test;
    while(test--)
        solve();
    return 0;
}