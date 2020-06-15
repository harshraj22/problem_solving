// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0

#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
int dp[N][N];

void init();
void solve();
int lps(int i, int j, string &s);

int main() {
	int test;	cin >> test;
	while (test--)
		solve();

	return 0;
}

void solve() {
	init();
	string s;	cin >> s;
	int n = s.size();
	cout << lps(0, n-1, s) << endl;
}

void init() {
	for (int i = 0; i < N; i += 1)
		for (int j = 0; j < N; j += 1)
			dp[i][j] = 0;
}

int lps(int left, int right, string &s) {
	if (left == right)
		return 1;
	else if (dp[left][right] > 0)
		return dp[left][right];
	else if (left > right)
		return 0;
	else if (s[left] == s[right])
		return dp[left][right] = 1 + lps(left+1, right-1, s) + 1;
	int s1 = lps(left+1, right, s), s2 = lps(left, right-1, s);
	return dp[left][right] = max(s1, s2);	
}

