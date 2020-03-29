// https://codeforces.com/problemset/problem/479/E

#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

const int N = 5e3 + 3;
int dp[N][N], pref[N][N];

void init() {
	for (int i = 0; i < N; i += 1) {
		for (int j = 0; j < N; j += 1) {
			dp[i][j] = 0;
			pref[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	init();
	int n, a, b, k;
	long long int mod = 1e9 + 7;
	cin >> n >> a >> b >> k;

	// if k == 0, num of combinations = 1
	for (int i = 1; i <= n; i += 1) {
		dp[i][0] = 1;
		pref[i][0] = pref[i-1][0] + dp[i][0];
		pref[i][0] %= mod;
	}

	for (int j = 1; j <= k; j += 1) {
		for (int i = 1; i <= n; i += 1) {
			int low = 0, high = 0;
			if (i < b) {
				high = b - 1, low = max(0, i - (b - i) + 1);
			} else if (i > b) {
				low = b + 1, high = min(n, i + (i - b) - 1);
			}
			dp[i][j] = (mod + pref[high][j-1] - pref[low][j-1])%mod + (dp[low][j-1] - dp[i][j-1])%mod;

			dp[i][j] = (mod + dp[i][j])%mod;
			pref[i][j] += pref[i-1][j] + dp[i][j];
			pref[i][j] = (mod + pref[i][j])%mod;
		}
	}

	cout << dp[a][k] << '\n';

	return 0;
}