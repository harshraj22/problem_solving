#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
	int n;	cin >> n;

    // dp[i] stores minimum number of operations required to reach to 'n'
	vector<int> dp(n+1,0);

    // from n-1, only one operation is required to reach to n
	dp[n-1] = 1;
	for (int i=n-2;i>=0;i--) {
		dp[i] = 1 + dp[i+1];
		if (i*2 <= n)
			dp[i] = min(dp[i], 1 + dp[i*2]);
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