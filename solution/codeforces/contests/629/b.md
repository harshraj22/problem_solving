```c++
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    ll cur = 0, k, n, diff;
    cin >> n >> k;
    ll first = n-1, second = n;
    diff = n - first;
    while (k > cur + diff) {
        cur += diff;
        first -= 1;
        diff = n - first;
    }

    while (k > cur + 1) {
        cur += 1;
        second -= 1;
    }

    string s(n+1, 'a');
    s[first] = 'b';
    s[second] = 'b';
    cout << s.substr(1) << '\n';

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