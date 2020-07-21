// https://practice.geeksforgeeks.org/problems/next-larger-element/0

// Debug : debug template
// Number : number theory 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()
#define IOS ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 0xFFFFFFFFFFFFFFFL;

typedef tree<int,null_type, /*greater<int>,*/
less<int>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// find_by_order() and order_of_key() returns pointers
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)

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

ll inline power(ll x, ll y, ll mod = 1e9+7, ll res = 1) {
	while(y > 0){
		if(y & 1)
			res = (res * x) % mod;
		y = (y >> 1); x = (x*x)% mod;
	}
	return res % mod;
}

string to_binary(ll num) {
	// long int to binary.
	return bitset<64> (num).to_string();
}

ll to_long(string s) {
	// binary string to long int
	return bitset<64> (s).to_ulong();
}

void solve(){
	int n;	cin >> n;
	vector<ll> nums(n), nextGreater;
	stack<ll> stk;
	for (auto &num: nums)
		cin >> num;
	for (int i = n-1; i >= 0; i -= 1) {
		while (!stk.empty() && stk.top() <= nums[i])
			stk.pop();
		if (stk.empty())
			nextGreater.push_back(-1);
		else 
			nextGreater.push_back(stk.top());
		stk.push(nums[i]);
	}

	reverse(all(nextGreater));
	for (auto num: nextGreater)
		cout << num << ' ';
	cout << '\n';
}

int main(){
	IOS;
	int test = 1;
	cin >> test; 
	while(test--)
		solve();
	return 0;
}






