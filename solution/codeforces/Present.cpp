// https://codeforces.com/problemset/problem/460/C
// Binary Search the answer

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

ll n,m,w;
vector<ll> a;

bool achievable(ll hei){
	vector<ll> cur = a, cnt(n+1,0);
	ll cur_sum = 0;

	for(auto &it:cur)
		it = min(it, hei);

	for(int i=0;i<n;i++){
		cur_sum += cnt[i];
		cnt[i] = max(0LL, cnt[i]);
		if(cur[i] + cur_sum < hei){
			ll req = hei - cur_sum - cur[i];
			cnt[i] += req;
			cur_sum += req;
			ll ind = min(n, i+w);
			cnt[ind] -= req;
		}
	}

	cur_sum = 0;
	for(auto it:cnt)
		cur_sum += max(0LL, it);

	if(cur_sum <= m)
		return true;
	return false;
}

void solve(){
	cin >> n >> m >> w;
	a.resize(n);
	for(auto &it:a)
		cin >> it;

	ll low = 0, high = 1e10;
	while(low < high){
		ll mid = (low+high+1)/2;
        // check if min_height = mid is achievable
		if(achievable(mid))
			low = mid;
		else 	
			high = mid-1;
	}
	cout << low << '\n';
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