// https://cses.fi/problemset/task/1637
// Another Iterative DP

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 1e6;

int main() {
	vector<int> dp(N+1, 0);

	for (int i = 1; i < dp.size(); i += 1) {
		string s = to_string(i);
		dp[i] = N + 2;
		for (auto ch: s) {
			if (ch == '0')
				continue;
			dp[i] = min(dp[i], 1+dp[i-(ch-'0')]);
		}
	}

	int n;	cin >> n;
	cout << dp[n] << '\n';

	return 0;
}

