* So much time was not needed for this

``` c++
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    ll a, b;    cin >> a >> b;
    ll g = __gcd(a, b);
    if (g == b)
        cout << 0 << '\n';
    else if (g == a)
        cout << a << '\n';
    else if (b < a) {
        b /= g;
        a /= g;
        cout << g*min(b-a%b, a%b) << '\n';
    }
    else {
        b /= g;
        a /= g;
        cout << g*min({a,b-a}) << '\n';
    }
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