// https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
// yet another standard dp 

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
    dp[a][b] = max(recur(a-1, b), recur(a, b-1));
    if (s1[a] == s2[b])
        dp[a][b] = max(dp[a][b], 1 + recur(a-1, b-1));
    return dp[a][b];
}

void solve(){
    cin >> n >> m;
    cin >> s1 >> s2;
    dp = vector<vector<int>> (n, vector<int> (m, -1));

    cout << recur(n-1, m-1) << '\n';
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