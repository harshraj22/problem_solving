// https://acm.timus.ru/problem.aspx?space=1&num=1423

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){
	int n;	cin >> n;
	string cyclic, original;
	cin >> original >> cyclic;

	// handle case for n == 1
	if (n == 1) {
		if (cyclic == original) 
			cout << 0 << '\n';
		else 
			cout << -1 << '\n';
		return;
	}

	// search cyclic in (original + original)
	string s = cyclic + '\0' + original +  original;
	int m = s.size();
	vector<int> pi(m, 0);

    // standard code for creating pi table
	for (int i = 1; i <= m; i += 1) {
		int len = pi[i-1];
		while(len && s[i] != s[len])
			len = pi[len-1];
		if (s[i] == s[len])
			len += 1;
		pi[i] = len;
	}

	int index = 0;
    // little bit involved calculation, use pen and paper
    // taking some examples to understand this calculation
    // of index
	for (int i = n + 2; i < m; i += 1) {
		if (pi[i] == n) {
			int indexInDouble = i - n - 1;
			index = n - (indexInDouble - n);
		}
	}

	cout << index - 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test = 1;
	// cin >> test;
	while(test--)
		solve();
	return 0;
}