// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int dp[100][100], n, m;
string s1, s2;

int recur(int l, int r) {
	if (l == n) return m - r;
	else if (r == m) return n - l;
	else if (dp[l][r] != -1)
		return dp[l][r];
	
	dp[l][r] = 1 + min(recur(l+1, r), recur(l, r+1));

	if (s1[l] == s2[r])
		dp[l][r] = min(dp[l][r], 1 + recur(l+1, r+1));

	return dp[l][r];
}

void solve() {
	for (int i = 0; i < 100; i += 1) {
		for (int j = 0; j < 100; j += 1)
			dp[i][j] = -1;
	}

	cin >> s1 >> s2;
	n = s1.size(); m = s2.size();

	cout << recur(0, 0) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int test = 1;
    cin >> test;
    while(test--)
        solve();
	
	return 0;
}