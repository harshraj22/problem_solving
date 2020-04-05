* First few are cakewalks here

``` c++
//=====================COMPILER OPTIMIZATION STARTS=======================
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//======================COMPILER OPTIMIZATION ENDS=======================

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    swap(a, b);
    swap(a, c);
    cout << a << ' ' << b << ' ' << c << '\n';

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