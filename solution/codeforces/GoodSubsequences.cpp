// https://codeforces.com/problemset/problem/264/B

//=====================COMPILER OPTIMIZATION STARTS=======================
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//======================COMPILER OPTIMIZATION ENDS=======================

//compile using : g++ -D DEB file.cpp
#ifdef DEB
	//to check from out of bounds errors
	#define _GLIBCXX_DEBUG
#endif
//=============================DEBUG PART ENDS===========================

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

ll power(ll x, ll y, ll mod = 1e9+7){
	ll res = 1;
	while(y > 0){
		if(y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x*x)% mod;
	}
	return res % mod;
}

const int N = 1e5+5;
vector<int> primes(N, 1);
map<int, int> largest;

void precalculate() {
	for (int i=2; i<primes.size(); i++) {
		if (primes[i]) {
			for (int j=i+i;j<primes.size();j+=i)
				primes[j] = 0;
		}
	}
}

vector<int> factorize(int val) {
	// finds prime factors of 'val' if exists
	if (val == 1) {
		return vector<int> (1,1);
	}

	vector<int> ans(0);
	int sq = sqrt(val) + 1;
	for (int i=2; i<sq; i++) {
		if (val%i == 0) {
			ans.push_back(i);
			while(val%i == 0)
				val /= i;
		}
	}
	
	if (val > 1)
		ans.push_back(val);

	return ans;
}

/* 
	Seems like a complex solution, but time complexity is O(Nsqrt(N)).
	The point to note is, product of first 20 primes is too large.Given
	the range of elements, iterating over one element's prime factors (
		once they have been found), is almost constant time operation.
	So, for each element, find its prime factors, and iterate over them
	(as gcd > 1) is required, 
 */

void solve(){
	precalculate();
	int n;	cin >> n;
	vector<int> v(n);
	for (auto &it:v)
		cin >> it;

	for (auto it:v) {
		// consider the lis, which ends with last element as 'it'
		vector<int> factors = factorize(it);
		int cur_ans = 0;
		for (auto factor:factors) {
			cur_ans = max(cur_ans, largest[factor]);
		}

		cur_ans += 1;
		for (auto factor:factors) {
			// for all possible elements before 'it' in the currently
			// being considered lis, update their answer
			if (largest[factor] < cur_ans)
				largest[factor] = cur_ans;
		}
	}

	int ans = 0;
	for (auto it:largest) 
		ans = max(ans, it.second);

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