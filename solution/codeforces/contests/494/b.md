``` c++
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    int a, b, x;
    cin >> a >> b >> x;
    deque<char> s={'0'}; string cur = "01";
    a -= 1;
    for (int i = 1; i < x; i += 1) {
        s.push_back(cur[i%2]);
        if (i%2)  b -=1 ;
        else   a -= 1;
    }
    // x - 1 times s[i] != s[i+1]
    if (!a) {
        while(b--)
            s.push_front('1');
        for (auto it:s) cout << it;
        cout << '\n';
        return;
    }

    if (x%2 == 1) {
        // last is 0
        while(a--)
            s.push_back('0');
        while(b--)
            s.push_back('1');
    }   else {
        while(b--)
            s.push_back('1');
        while(a--)
            s.push_back('0');
    }
    for (auto it:s)
        cout << it;
    cout << '\n';
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