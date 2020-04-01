``` c++
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
const int N = 5e3 + 2;

double dp[N][N];

vector<ll> pref, input;
int n, k;

double recur(int left, int right) {
    if (right - left + 1 < k)
        return -1.0;
    double total = (pref[right] - pref[left] + input[left])*1.0/(right-left+1);
    if (dp[left][right] > 0)
        return dp[left][right];

    return dp[left][right] = max({total, recur(left, right-1), recur(left+1, right)});
}

void solve(){
    cin >> n >> k;
    input.resize(n);
    pref.resize(n);
    for (auto &it:input)
        cin >> it;
    partial_sum(input.begin(), input.end(), pref.begin());
    double total = (pref.back()*1.0)/n;

    cout << fixed << setprecision(12) << max({total, recur(0, n-2), recur(1, n-1)}) << '\n';
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
```