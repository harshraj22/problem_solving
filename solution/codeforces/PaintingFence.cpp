// https://codeforces.com/problemset/problem/448/C
// Basic Divide and Conquer
/*  Idea: 
        Subtract *min_element from all elements of the array,
        we get array of positive integers separated with 0s.
        find answer for these separated arrays
*/

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

ll Get(vector<ll> a, ll mn){
	if(a.size() == 1)
		return 1;
	vector<ll> v;
	ll sum = mn,Mn = 1e10;
	for(auto it:a){
		it -= mn;
		if(it > 0){
			v.push_back(it);
			Mn = min(Mn, it);
			continue;
		}
		else if(v.size()){
			sum += min(Get(v, Mn),(ll)v.size());
			Mn = 1e10;
			v.resize(0);
		}
		Mn = 1e10;
	}

	if(v.size()){
		sum += min(Get(v, Mn),(ll)v.size());
		Mn = 1e10;
		v.clear();
	}

	return min(sum, (ll)a.size());
}

void solve(){
	ll n;	cin >> n;
	vector<ll> a(n);
	for(auto &it:a)
		cin >> it;
	ll mn = *min_element(a.begin(),a.end());
	cout << min(n,Get(a,mn)) << '\n';
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
