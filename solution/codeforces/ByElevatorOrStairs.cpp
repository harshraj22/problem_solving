// https://codeforces.com/problemset/problem/1249/E

// Basic DP
// Time: O(n) space: O(n), can be made in O(1) space as 
//      dp[..][i] always requires dp[..][i-1] and not any previous values
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    int n, c;   cin >> n >> c;
    vector<ll> v(n+1), b(n+1);
    vector<vector<ll>> dp(2, vector<ll> (n+1, 0));
    for (int i = 1; i < n; i += 1)
        cin >> v[i];
    for (int i = 1; i < n; i += 1)
        cin >> b[i];

    // dp[0][i] : using stairs
    // dp[1][i] : using elevators
    dp[1][1] = c;
    
    for (int i = 2; i <= n; i += 1) {
        dp[0][i] = v[i-1] + min(dp[0][i-1], dp[1][i-1]);
        dp[1][i] = b[i-1] + min(dp[1][i-1], c + dp[0][i-1]);
    }

    for (int i = 1; i <= n; i += 1)
        cout << min(dp[0][i], dp[1][i]) << ' ';
    cout << '\n';
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