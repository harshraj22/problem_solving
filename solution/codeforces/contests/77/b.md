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

void solve(){
    long long int a, b;
    cin >> a >> b;
    if (min(a,b)*2 < max(a,b)) {
        cout << "NO\n";
        return;
    }   else if (a == b) {
        if (a+b == 0) 
            cout << "yes\n";
        else if (a % 3)
            cout << "no\n";
        else 
            cout << "yes\n";
        return;
    }

    // b > a
    if (b < a)
        swap(a, b);
    int diff = b - a;

    if (diff % 2 == 1) {
        a -= 1;
        b -= 2;
        diff = b - a;
    }

    if (a+b == 0) {
        cout << "yes\n";
        return;
    }    

    if (diff % 2 == 0) {
        a -= diff;
        b -= diff*2;
        // a == b now
        if (a+b == 0) 
            cout << "yes\n";
        else if (a % 3)
            cout << "no\n";
        else 
            cout << "yes\n";
        return;
    }

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
```