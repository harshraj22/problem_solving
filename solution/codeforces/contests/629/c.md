```c++
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    int n, gr = 0;  cin >> n;
    string s, a, b; cin >> s;
    for (int i = 0; i < n; i += 1) {
        if (gr == 0) {
            if (s[i] == '0') {
                a += '0';
                b += '0';
            }
            else if (s[i] == '2') {
                a += '1';
                b += '1';
            }
            else {
                a += '1';
                b += '0';
                gr = 1;
            }
        }   
        else {
            if (s[i] == '0') {
                a += '0';
                b += '0';
            }
            else if (s[i] == '1') {
                a += '0';
                b += '1';
            }
            else if (s[i] == '2') {
                a += '0';
                b += '2';
            }
        }
    }

    cout << a << '\n' << b << '\n';

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