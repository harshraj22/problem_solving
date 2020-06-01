// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

// Debug : debug template
// Number : number theory 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pi pair<ll,ll>
#define IOS ios_base::sync_with_stdio(false);    cin.tie(0);    cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 0xFFFFFFFFFFFFFFFL;

typedef tree<int,null_type, /*greater<int>,*/
less<int>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// find_by_order() and order_of_key() returns pointers
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)

ll inline power(ll x, ll y, ll mod = 1e9+7, ll res = 1) {
    while(y > 0){
        if(y & 1)
            res = (res * x) % mod;
        y = (y >> 1); x = (x*x)% mod;
    }
    return res % mod;
}

void solve(){
    string s, t; cin >> s;
    vector<string> v;
    for (auto ch: s) {
        if (ch == '.') {
            if (t.size()) {
                v.push_back(t);
                t = "";
            }
        }
        else 
            t += ch;
    }

    if (t.size()) {
        v.push_back(t);
        t = "";
    }

    reverse(v.begin(), v.end());
    for (auto word: v) {
        t += word;
        t += '.';
    }

    cout << t.substr(0, (int)t.size()-1) << '\n';
}

int main(){
    IOS;
    int test=1;
    cin >> test; 
    while(test--)
        solve();
    return 0;
}