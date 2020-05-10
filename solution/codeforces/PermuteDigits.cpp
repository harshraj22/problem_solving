// https://codeforces.com/problemset/problem/915/C

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

ll inline power(ll x, ll y, ll mod = 1e9+7){
	ll res = 1;
	while(y > 0){
		if(y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x*x)% mod;
	}
	return res % mod;
}

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

void solve(){
	string a, b;	int n;
	cin >> a >> b;	n = b.size();
	if (b.size() > a.size()) {
		sort(a.begin(), a.end(), greater<char>());
		cout << a << '\n';
		return;
	}

	// now a.size() == b.size();
	map<char,int> freq;
	for (auto ch: a)
		freq[ch] += 1;

	string ans;
	for (int i = 0; i < n; i += 1) {
		if (freq.find(b[i]) != freq.end()) {
			ans += b[i];
			freq[b[i]] -= 1;
			if (freq[b[i]] == 0)
				freq.erase(b[i]);
		}
		else if (freq.lower_bound(b[i]) != freq.begin()) {
			auto it = prev(freq.lower_bound(b[i]));
			ans += it->first;
			it->second -= 1;
			for (auto it = freq.rbegin(); it != freq.rend(); it++) {
				while(it->second) {
					ans += it->first;
					it->second = it->second - 1;
				}
			}
			i = n;
		}
		else {
			while(b[i] <= freq.begin()->first) {
				freq[ans.back()] += 1;
				ans.pop_back();	i -= 1;
			}	
			// trace(ans);	trace(freq);

			auto it = prev(freq.lower_bound(b[i]));
			ans += it->first;
			it->second -= 1;
			for (auto it = freq.rbegin(); it != freq.rend(); it++) {
				while(it->second) {
					ans += it->first;
					it->second = it->second - 1;
				}
			}
			i = n;

		}
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