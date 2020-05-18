```c++
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    ll a, b;
    cin >> a >> b;
    ll var = a % b;
    if (var == 0) 
        cout << 0 << '\n';
    else 
        cout << b-var << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test = 1;
    cin >> test;
    while(test--)
        solve();
    return 0;
}

```
