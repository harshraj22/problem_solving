// https://www.codechef.com/problems/KAN13C

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void solve() {
	string s;	cin >> s;
	while(s != "End") {
		int n = s.size();
		vector<int> pi(n, 0);

		for (int i = 1; i < n; i += 1) {
			int len = pi[i-1];
			while(len && s[i] != s[len])
				len = pi[len - 1];
			if (s[i] == s[len])
				len += 1;
			pi[i] = len;
		}

		for (int i = 0; i < n; i += 1) {
			cout << pi[i];
			if (i < n - 1)
				cout << ' ';
			else 
				cout << '\n';
		}

		cin >> s;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test = 1;
	// cin >> test;
	while(test--)
		solve();

	return 0;
}