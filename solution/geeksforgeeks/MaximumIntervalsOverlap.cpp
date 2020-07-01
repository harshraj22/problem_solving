// https://practice.geeksforgeeks.org/problems/maximum-intervals-overlap/0

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int numGuests;	cin >> numGuests;
	pair<int, int> ans = {0, 0};
	vector<pair<int, int>> times(numGuests);
	multiset<int> activeGuests;

	for (int i = 0; i < numGuests; i += 1) 
		cin >> times[i].first;		
	for (int i = 0; i < numGuests; i += 1) 
		cin >> times[i].second;

	sort(times.begin(), times.end());
	for (auto points: times) {
		while (activeGuests.empty() == false && *activeGuests.begin() < points.first)
			activeGuests.erase(activeGuests.begin());
		activeGuests.insert(points.second);
		if (ans.first < activeGuests.size()) 
			ans = {activeGuests.size(), points.first};
	} 

	cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test;
	cin >> test;
	while (test--)
		solve();

	return 0;
}
