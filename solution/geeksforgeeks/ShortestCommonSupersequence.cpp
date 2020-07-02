// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0

#include <bits/stdc++.h>
using namespace std;

string s1, s2;
vector<vector<int>> dp;

int shortestCommonSubseq(int n, int m) {
	if (n == s1.size())
		return abs(m - (int)s2.size());
	else if (m == s2.size())
		return abs(n - (int)s1.size());
	else if (dp[n][m] != -1)
		return dp[n][m];
	else if (s1[n] == s2[m])
		return dp[n][m] = 1 + shortestCommonSubseq(n+1, m+1);
	return dp[n][m] = 1 + min(shortestCommonSubseq(n+1, m), shortestCommonSubseq(n, m+1));
}

void solve() {
	cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	dp = vector<vector<int>> (n, vector<int> (m, -1));
	cout << shortestCommonSubseq(0, 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test;	cin >> test;
	while (test--)
		solve();

	return 0;
}
