* Cakewalk again

``` c++
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    int n, m;   cin >> n >> m;
    int ans = 0;
    vector<ll> v(n);
    for (int i = 0; i < n; i += 1) {
        cin >> v[i];
    }

    ll sum = accumulate(v.begin(), v.end(), 0LL);
    for (int i = 0; i < n; i += 1) {
        if (v[i]*4*m >= sum)
            ans += 1;
    }
    
    if (ans >= m)
        cout << "Yes\n";
    else 
        cout << "No\n";
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