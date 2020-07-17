// https://cses.fi/problemset/task/1746

// Debug : debug template
// Number : number theory 
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()
#define IOS ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 0xFFFFFFFFFFFFFFFL;

const int N = 1e5+2;
const int M = 100+2;
const int mod = 1e9+7;

void solve(){
	int n, m;	cin >> n >> m;
	vector<int> arr(n);
	vector<vector<ll>> dp(M, vector<ll> (N, 0));
	for (auto &num: arr)
		cin >> num;

	if (arr[0] != 0)
		dp[arr[0]][0] = 1;
	else {
		for (int val = 1; val <= m; val += 1)
			dp[val][0] = 1;
	}

	for (int i = 1; i < n; i += 1) {
		if (arr[i] != 0) 
			dp[arr[i]][i] += (dp[arr[i]-1][i-1] + dp[arr[i]][i-1] + dp[arr[i]+1][i-1]) % mod;
		else {
			for (int val = 1; val <= m; val += 1) 
				dp[val][i] = ( dp[val-1][i-1] + dp[val][i-1] + dp[val+1][i-1] ) % mod;
		}
	}

	ll sum = 0;
	for (int val = 1; val <= m; val += 1) 
		sum = (sum + dp[val][n-1]) % mod;
	
	cout << sum << '\n';	
}

int main(){
	IOS;
	int test = 1;
	// cin >> test; 
	while(test--)
		solve();
	return 0;
}






