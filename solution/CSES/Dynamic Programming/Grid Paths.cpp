// https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;

int main() {
	int n;	cin >> n;
	char grid[n][n];
	vector<vector<int>> numWays(n, vector<int> (n, -1));

	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < n; j += 1)
			cin >> grid[i][j];
	}

	auto isValid = [&n](int x, int y) {
		if (x < 0 || y < 0) return false;
		else if (x >= n || y >= n) return false;
		return true;
	};

	numWays[0][0] = (grid[0][0] == '.');
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < n; j += 1) {
			// to escape altering value of numWays[0][0]
			if (numWays[i][j] != -1)
				continue;
			numWays[i][j] = 0;
			if (grid[i][j] == '*')
				continue;

			numWays[i][j] += (isValid(i-1, j) ? numWays[i-1][j]: 0);
			numWays[i][j] += (isValid(i, j-1) ? numWays[i][j-1]: 0);
			numWays[i][j] %= mod;
		}
	}

	numWays[0][0] = (grid[0][0] == '.');

	cout << numWays[n-1][n-1] << '\n';

	return 0;
}
