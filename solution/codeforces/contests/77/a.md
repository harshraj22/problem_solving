``` c++
//=====================COMPILER OPTIMIZATION STARTS=======================
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//======================COMPILER OPTIMIZATION ENDS=======================

//compile using : g++ -D DEB file.cpp
#ifdef DEB
    //to check from out of bounds errors
    #define _GLIBCXX_DEBUG
#endif
//=============================DEBUG PART ENDS===========================

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

ll power(ll x, ll y, ll mod = 1e9+7){
    ll res = 1;
    while(y > 0){
        if(y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x*x)% mod;
    }
    return res % mod;
}

long long int sq(ll a) {
    return a * a;
}

void solve(){
    long long int ans = 0, n;   cin >> n;
    vector<long long int> c(n), sum(n);
    for (int i = 0; i < n; i += 1) {
        cin >> c[i] >> sum[i];
    }

    for (int i = 0; i < n; i += 1) {
        cout << (c[i] - sum[i]%c[i])*sq(sum[i]/c[i]) +(sum[i]%c[i])*sq(sum[i]/c[i] + 1) << '\n';
    }

    // cout << ans << '\n';
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