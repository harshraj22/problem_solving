// https://csacademy.com/contest/archive/task/divisor_clique/
// Simple DP

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    int n, ans = 0; cin >> n;
    vector<int> v(n), dp(n, 1);
    
    for (auto &it: v)
        cin >> it;
    sort(v.begin(), v.end());
    
    for (int i = n-1; i >= 0; i -= 1) {
        for (int j = i+1; j < n; j += 1) {
            if (v[j] % v[i] == 0) 
                dp[i] = max(dp[i], dp[j] + 1);
        }
    } 

    cout << *max_element(dp.begin(), dp.end()) << '\n';
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