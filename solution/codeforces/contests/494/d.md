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
    int n, q;   cin >> n >> q;
    vector<int> a(n), freq(33, 0);
    for (auto &it:a) {
        cin >> it;
        int firstBit = (int)log2(it);
        freq[firstBit] += 1;
    }

    while (q--) {
        int target, num = 0; cin >> target;
        vector<int> cur = freq, query(33, 0);
        for (int i = 32; i >= 0; i -= 1) {
            if(target & (1LL<<i))
                query[i] += 1;
        } 

        for (int i = 32; i >= 0; i -= 1) {
            if (query[i] && cur[i]) {
                int toAdd = min(query[i], cur[i]);
                num += toAdd;
                query[i] -= toAdd;
                cur[i] -= toAdd;
            }
            if (i > 0) {
                // cur[i-1] += cur[i] * 2;
                query[i-1] += query[i] * 2;
            }
        }

        if (query[0])
            cout << "-1\n";
        else 
            cout << num << '\n';

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