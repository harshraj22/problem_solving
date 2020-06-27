// https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem/0

#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

void print(string s) {
    for (auto ch: s)
        cout << ch << ' ';
    cout << endl;
}

int main() {
	string symbols = "!#$%&*@^~";
	int test;	cin >> test;
	while (test--) {
		int n;	cin >> n;
		string matched;
		vector<char> nuts(n), bolts(n);
		for (auto &ch: nuts)
			cin >> ch;
		for (auto &ch: bolts)
			cin >> ch;
		sort(all(nuts));
		sort(all(bolts));

		for (auto ch: symbols) {
			if (binary_search(all(nuts), ch) && binary_search(all(bolts), ch))
				matched += ch;
		}

		print(matched);
		print(matched);
	}

	return 0;
}
