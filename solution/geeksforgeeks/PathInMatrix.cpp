// https://practice.geeksforgeeks.org/problems/path-in-matrix/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

void solve(){
    int n;  cin >> n;
    vector<vector<int>> dp(n+1, vector<int> (n+2, 0));

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1)
            cin >> dp[i][j];
    }     

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            dp[i][j] += max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
        }
    }

    cout << *max_element(all(dp.back())) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    int test = 1;
    cin >> test;
    while(test--)
        solve();
    return 0;
}