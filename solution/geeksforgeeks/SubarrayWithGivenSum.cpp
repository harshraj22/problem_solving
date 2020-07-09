// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
// Two Pointers,
// 		Time: O(n)
// 		Space: O(1)

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define ll long long int

void solve() {
	ll n, sum, cur_sum = 0, left = 0, right = 0;
	cin >> n >> sum;
	vector<ll> nums(n);
	
	for (auto &num: nums)	
		cin >> num;

	while (right < n) {
		if (cur_sum < sum) {
			cur_sum += nums[right];
			right += 1;
		}
		else if (cur_sum == sum) {
			cout << left+1 << ' ' << right << '\n';
			return;
		}
		else {
			cur_sum -= nums[left];
			left += 1;
		}
	}

	while (left < right) {
		if (cur_sum == sum) {
			cout << left+1 << ' ' << right << '\n';
			return;
		}
		cur_sum -= nums[left];
		left += 1;
	}

	cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test = 1;
	cin >> test;
	while (test--)
		solve();

	return 0;
}
