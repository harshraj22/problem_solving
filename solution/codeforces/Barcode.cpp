// https://codeforces.com/problemset/problem/225/C

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    // ll arr[n+1][m+1];
    vector<vector<ll>> arr(n+1, vector<ll>(m+1, 0));

    for (ll i = 1; i <= n; i += 1) {
        for (ll j = 1; j <= m; j += 1) {
            char ch;    cin >> ch;
            arr[i][j] = (ch == '#');  
        }
    }

    auto count_col = [&](ll col, ll ch)->ll {
        // counts number of changes required to change each 
        // char in column = 'col' to char = 'ch'
        ll ans = 0;
        for (ll row = 1; row <= n; row += 1) 
            ans += (arr[row][col] != ch);
        return ans;
    };

    vector<vector<ll>> pref(2, vector<ll>(m+1, 0)), dp(2, vector<ll>(m+1, (ll)1e7));
    for (ll i = 1; i <= m; i += 1) {
        pref[0][i] = count_col(i, 0) + pref[0][i-1];
        pref[1][i] = count_col(i, 1) + pref[1][i-1];
    }

    dp[0][0] = dp[1][0] = 0;

    // range [x, y] => from i-y to i-x
    for (ll i = 1; i <= m; i += 1) {
        if (i < max(y+1, x+x)) {
            dp[0][i] = pref[0][i];
            dp[1][i] = pref[1][i];
            // continue;
        }

        for (ll j = max(x+1, i-y+1); j <= i-x+1; j += 1) {
            // from j to i, it should be same colour
            dp[0][i] = min(dp[0][i], dp[1][j-1] + pref[0][i] - pref[0][j-1]);
            dp[1][i] = min(dp[1][i], dp[0][j-1] + pref[1][i] - pref[1][j-1]);
        }

        for (auto j: {0, 1}) {
            if (dp[j][i] > (int)1e6)
                dp[j][i] = pref[j][i];
        }

    }

    cout << min(dp[0].back(), dp[1].back()) << '\n';
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