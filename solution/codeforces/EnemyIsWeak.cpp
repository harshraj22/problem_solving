// https://codeforces.com/problemset/problem/61/E
// Idea from editorial: https://codeforces.com/blog/entry/1347
// I would have probably gone with persistent seg tree

/* 
Used:
    Coordinate compression to avoid use of persistent segment tree 
    A segment tree with sum query and point update
    Policy based data structure for counting inversions
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pi pair<ll,ll>

typedef tree< int, null_type,
less<int>, rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int N = 1e6+6;
vector<ll> seg(4*N), expand, inv;
map<int, int> compress;

// -------------------<Debugging stuff>-------------------
#define TRACE
 
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << std::endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
    // https://qr.ae/TSWZ6e
    // https://discuss.codechef.com/t/trace-__f-__va_args__-__va_args__/19200
    template < typename F, typename S >
    ostream& operator << ( ostream& os, const pair< F, S > & p ) {
        return os << "(" << p.first << ", " << p.second << ")";
    }
    template < typename T >
    ostream &operator << ( ostream & os, const vector< T > &v ) {
        os << "{";
        typename vector< T > :: const_iterator it;
        for( it = v.begin(); it != v.end(); it++ ) {
            if( it != v.begin() ) os << ", ";
            os << *it;
        }
        return os << "}";
    }
    template < typename T >
    ostream &operator << ( ostream & os, const set< T > &v ) {
        os << "[";
        typename set< T > :: const_iterator it;
        for ( it = v.begin(); it != v.end(); it++ ) {
            if( it != v.begin() ) os << ", ";
            os << *it;
        }
        return os << "]";
    }
    template < typename T >
    ostream &operator << ( ostream & os, const multiset< T > &v ) {
        os << "[";
        for(auto it = v.begin(); it != v.end(); ++it) {
            if( it != v.begin() ) os << ", ";
                os << *it;
        }
        return os << "]";
    }
    template < typename F, typename S >
    ostream &operator << ( ostream & os, const map< F, S > &v ) {
        os << "[";
        typename map< F , S >::const_iterator it;
        for( it = v.begin(); it != v.end(); it++ ) {
            if( it != v.begin() ) os << ", ";
            os << it -> first << " = " << it -> second ;
        }
        return os << "]";
    }
#else
    #define trace(...)
#endif
 
// ------------------</Debugging stuff>-------------------


ll query(int node, int sl, int sr, int ql, int qr) {
    if (qr < sl || ql > sr || ql > qr)
        return 0;
    else if (ql <= sl && qr >= sr)
        return seg[node];
    int mid = (sl+sr)/2;
    return query(node*2, sl, mid, ql, qr) + query(node*2+1, mid+1, sr, ql, qr);
}

void update(int node, int sl, int sr, int up, ll uv) {
    if (sl == sr) {
        seg[node] += uv;
        return;
    }

    int mid = (sl+sr)/2;
    if (up <= mid)
        update(node*2, sl, mid, up, uv);
    else 
        update(node*2+1, mid+1, sr, up, uv);
    seg[node] = seg[node*2] + seg[node*2+1];
}

void solve(){
    ordered_set st; ll n, ans = 0;  cin >> n;
    expand.resize(n+1); inv.resize(n+1, 0);
    vector<int> A(n+1);
    for (int i = 1; i <= n; i += 1) {
        cin >> A[i]; expand[i] = A[i];
    }

    // coordinate compression
    sort(expand.begin()+1, expand.end());
    for (int i = 1; i <= n; i += 1) 
        compress[expand[i]] = i;
    
    // Counting inversions
    // inv[i]: num of j such A[j] < A[i] for j > i
    for (int i = n; i > 0; i -= 1) {
        inv[i] = st.order_of_key(A[i]);
        st.insert(A[i]);
    }

    // trace(inv); trace(expand); trace(compress);

    // build(1, 1, n); : not required, update on the go
    for (int i = n; i > 0; i -= 1) {
        int value = compress[A[i]];
        ans += query(1, 1, n, 1, value-1);
        // trace(i, query(1, 1, n, 1, value-1));
        update(1, 1, n, value, inv[i]);
    }

    cout << ans << '\n';
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