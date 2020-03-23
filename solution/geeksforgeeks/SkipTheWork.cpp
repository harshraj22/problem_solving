// https://practice.geeksforgeeks.org/problems/skip-the-work/0

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
	int n;	cin >> n;
	vector<int> tasks(n);

	// taking input
	for (auto &task:tasks)
		cin >> task;

	// dp[0][i] means, minimum amount of time when i'th task is excluded, 
	// and tasks to be considered are from tasks[i]...tasks[n]
	int dp[2][n];

	dp[0][n-1] = 0;
	dp[1][n-1] = tasks[n-1];

	for (int i=n-2;i>=0;i--) {
		// as two consecutive tasks can't be escaped, if i'th task is escaped
		// i+1'th task must be included
		dp[0][i] = dp[1][i+1];
		// if i'th task is included, i+1'th task can or can't be included, so
		// choose whichever gives optimal result
		dp[1][i] = tasks[i] + min(dp[0][i+1] , dp[1][i+1]);
	}

	cout << min(dp[0][0], dp[1][0]) << '\n';
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