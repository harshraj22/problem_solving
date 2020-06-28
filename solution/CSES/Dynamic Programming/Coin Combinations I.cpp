// https://cses.fi/problemset/task/1635/
// Iterative DP is faster than Recursive DP
// Effects are visible on tight constraints

#include <bits/stdc++.h>
using namespace std;

// The following additional optimization causes TLE
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#define ll long long int

const int N = 1e6;
const int mod = 1e9 + 7;

// using arrays instead of vectors as they are faster
int dp[100+1][N+1];
ll coins[100+1], sum[N+1];

// using mod (%) causes TLE as mod is expensive operation
int modIt(long long int num) {
	while (num >= mod)
		num -= mod;
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	// vector<vector<int>> dp(100+1, vector<int> (N+1, 0));
	ll n, x;	cin >> n >> x;
	// vector<ll> coins(n), sum(N+1, 0);

	for (auto &coin: coins)
		cin >> coin;

	// if money is 0, req no of ways is 1
	for (int i = 0; i < 100+1; i += 1)
		dp[i][0] = 1;
	sum[0] = 1;

	// dp[index][money]: num of ways when coin at pos=index must be included
	for (int money = 1; money < N+1; money += 1) {
		for (int index = 0; index < n; index += 1) {
			// if the current coin can't be included, num of ways = 0
			if (coins[index] > money)
				dp[index][money] = 0;
			// else include the current coin, and try all possible coins for next step
			else 
				dp[index][money] = sum[money-coins[index]];
			sum[money] = modIt(sum[money] + dp[index][money]);
		}
	}

	// sum[money]: num of ways to disintegrate money
	cout << sum[x] << '\n';

	return 0;
}

