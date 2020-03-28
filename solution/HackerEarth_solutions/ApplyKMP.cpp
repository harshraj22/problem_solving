// https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/problem-to-be-linked-with-kmp-tutorial-1/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	string p, t;
	cin >> p >> t;
	// find p in t

    // null character: a delimiter that is mostly
    // not included in strings given as input
    // on online judges
	t = p + '\0' + t;

    // build pi table for new string t, remember, we
    // chose such a delimiter so that max value of 
    // pi table may be p.size() and it will be when
    // we find occurence of 'p' in new 't'
	int n = t.size(), ans = 0;

    // pi[i] contains lenght of longest proper
    // suffix (ending at 'i') which is also a prefix 
	vector<int> pi (n, 0);

    // common code for generating pi table
	for (int i = 1; i < n; i += 1) {
		int l = pi[i-1];
		while (l && t[l] != t[i])
			l = pi[l-1];
		if (t[l] == t[i])
			l += 1;
		pi[i] = l;
	}

	n = p.size();

	for (int i = n; i < pi.size(); i += 1) {
		int num = pi[i];
		if (num == n)
			ans += 1;
	}

	cout << ans << '\n';

	return 0;
}
