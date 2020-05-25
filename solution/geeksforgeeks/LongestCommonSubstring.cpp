// https://practice.geeksforgeeks.org/problems/longest-common-substring/0
// another standard dp based solution

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

string s1, s2;
int n, m;
vector<vector<int>> dp;

int recur(int a, int b) {
    if (a < 0 || b < 0)
        return 0;
    else if (dp[a][b] != -1)
        return dp[a][b];
    else if (s1[a] != s2[b])
        return dp[a][b] = 0;
    return dp[a][b] = 1 + recur(a-1, b-1);
}

void solve(){
    cin >> n >> m;
    cin >> s1 >> s2;
    dp = vector<vector<int>> (n, vector<int> (m, -1));
    for (auto &it: dp)
        fill(all(it), -1);

    int ans = 0;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1)
            ans = max(ans, recur(i, j));
    }

    cout << ans << '\n';
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