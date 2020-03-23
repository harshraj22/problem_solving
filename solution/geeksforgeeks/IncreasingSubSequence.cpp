// https://practice.geeksforgeeks.org/problems/increasing-sub-sequence/0

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
	string s;	cin >> s;
	int n = s.size();
	vector<int> dp(n,0);

	for (int i=n-1;i>=0;i--) {
		for (int j=i+1;j<n;j++) {
			if (s[j] > s[i])
				dp[i] = max(dp[i], dp[j]);
		}
		dp[i] += 1;
	}

	cout << *max_element(dp.begin(), dp.end()) << '\n';
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
testcase = int(input())
for test in range(testcase):
    s = input()
    n = len(s)
    dp = [0 for _ in s]
    for index, val in enumerate(dp[::-1]):
        index = n - index - 1
        for j in range(index+1, n):
            if s[j] > s[index]:
                dp[index] = max(dp[index], dp[j])
        dp[index] += 1

    print(max(dp))

*/