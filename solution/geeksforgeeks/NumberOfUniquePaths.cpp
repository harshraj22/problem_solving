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

void solve(){
	int n,m;	cin >> n >> m;
	int dp[n+1][m+1];
    // dp[i][j] stores number of unique paths from (i,j) to (n-1,m-1)

    // initialize with 0 value
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=m;j++){
			dp[i][j] = 0;
		}
	}

	dp[n-1][m-1] = 1;

	for (int i=n-1;i>=0;i--) {
		for (int j=m-1;j>=0;j--) {
            // number of path is sum of number of path from below, and right across
            // += takes care of our initialization of (n-1,m-1) to 1 and others to 0
			dp[i][j] += dp[i+1][j] + dp[i][j+1];
		}
	}

	cout << dp[0][0] << '\n';

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