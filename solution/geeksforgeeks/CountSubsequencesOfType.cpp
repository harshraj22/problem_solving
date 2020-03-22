// Basic Dp : https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck4425/1
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
	string s;	cin >> s;
	int n = s.size(), ans = 0;

	int dp[n+1];
	// dp[i] stores number of subseq starting at i, and are in order
	// for subseq starting with c, order is c*c*c...
	// for subseq starting with b, order is b*b*b*...c*c*c*c...
	// for subseq starting with a, order is a*a*a*...b*b*b*b...c*c*c....

	for (int i=0;i<=n;i++)
		dp[i] = 0;
	
	for (int i=n-1;i>=0;i--) {
		for (int j=i+1; j<n; j++) {
			if (s[i] == 'a' && s[j] != 'c') {
				dp[i] += dp[j];

			} else if (s[i] == 'b' && s[j] != 'a') {
				dp[i] += dp[j];

			} else if (s[i] == 'c' && s[j] == 'c') {
				dp[i] += dp[j];

			}
		}

		if (s[i] == 'c')
			dp[i] += 1;
	}

	for (int i=0;i<n;i++) {
		if (s[i] == 'a')
			ans += dp[i];
	}

	// answer is number of such subsequences which start with 'a'

	cout << ans << '\n';
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