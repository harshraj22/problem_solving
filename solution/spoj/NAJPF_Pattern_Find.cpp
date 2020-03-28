#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void solve() {
	string a, b;	cin >> a >> b;
	// find b in a
	a = b + '\0' + a;
	int n = a.size();

	vector<int> pi(n, 0);

	for (int i = b.size(); i < n; i += 1) {
		int len = pi[i-1];
		while(len && a[len] != a[i])
			len = pi[len-1];
		if (a[len] == a[i])
			len += 1;
		pi[i] = len;
	}

	int freq = count(pi.begin()+b.size(), pi.end(), (int)b.size());
	if (freq == 0) {
		cout << "Not Found\n";
		return;
	}	else {
		cout << freq << '\n';
		for (int i = b.size(); i < n; i += 1) {
			if (pi[i] == b.size()) 
				cout << i - 2*b.size() + 1 << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test = 1;
	cin >> test;
	while(test--)
		solve();

	return 0;
}