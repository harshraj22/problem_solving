// https://practice.geeksforgeeks.org/problems/count-number-of-hops/0

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

	// dp[i] stores number of ways to reach from 'i' to 'n'
	vector<int> dp(n+5,0);
	dp[n] = 1;

	for (int i=n-1;i>=0;i--) {
		dp[i] += dp[i+1] + dp[i+2] + dp[i+3];
	}

	cout << dp[0] << '\n';
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



/*
# I know this way of iterating is too poor. If you find some better way, 
# please raise an issue. Don't ask for range(x, y, -1) thing.

testcase = int(input())
for test in range(testcase):
    target = int(input())
    dp = [0 for _ in range(target+6)]
    dp[target] = 1

    for index, value in reversed(list(enumerate(dp))):
        try:
            dp[index] += dp[index+1] + dp[index+2] + dp[index+3]
        except IndexError:
            continue

    print(dp[0])

*/