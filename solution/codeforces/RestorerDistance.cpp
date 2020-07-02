// https://codeforces.com/contest/1355/problem/E
// See for details of algo: https://github.com/harshraj22/problem_solving/blob/master/solution/codeforces/DevuAndHisBrother.cpp

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()
#define IOS ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);

ll N, A, R, M, costOfExchange;	
vector<ll> heights, pref;

// given height=h, find cost of makeing all heights = h
ll cost(ll h) {
	// less: total height req to make all  heights < h equal to h
	// more: total height req to make all  heights > h equal to h
	ll less = 0, more = 0, ans = 0;

	// for (auto height: heights) {
	// 	if (height < h)
	// 		less += (h - height);
	// 	else 
	// 		more += (height - h);
	// }

	// first index where height >= h
	ll firstIndex = lower_bound(all(heights), h) - heights.begin();
	ll oneMoreLastIndex = upper_bound(all(heights), h) - heights.begin();

	if (firstIndex > 0)
		less = abs(pref[firstIndex-1] - firstIndex*h);

	if (oneMoreLastIndex > 0)
		more = pref.back() - pref[oneMoreLastIndex-1] - (N-oneMoreLastIndex)*h;
	else if (oneMoreLastIndex == 0)
		more = pref.back() - (N-oneMoreLastIndex)*h; 

	ll num = min(less, more);
	ans += costOfExchange * num;

	less -= num;	
	more -= num;
	ans += (less*A);
	ans += (more*R);

	return ans;
}

void solve(){
	cin >> N >> A >> R >> M;
	costOfExchange = min(M, R+A);

	heights = vector<ll> (N);
	for (auto &height: heights)
		cin >> height;

	sort(all(heights));
	pref = vector<ll> (N, heights[0]);
	for (int i = 1; i < N; i += 1)
		pref[i] = pref[i-1] + heights[i];

	// ternary search the required height
	ll low = *min_element(all(heights)), high = *max_element(all(heights));

	// loop breaks when low is close to high (not necessarily equal)
	while (low < high) {
		ll mid1 = low + (high - low)/3;
		ll mid2 = high - (high-low)/3;

		if (low == mid1 || high == mid2)
			break;

		ll c1 = cost(mid1), c2 = cost(mid2);

		if (c2 > c1) 
			high = mid2;
		else if (c1 > c2) 
			low = mid1;
		else {
			high = mid2;
			low = mid1;
		}
	}

	assert(high-low < 1e6);
	// to ensure low = high and not low is close to high
	while (low < high) {
		if (cost(low) < cost(high))
			high -= 1;
		else
			low += 1;
	}

	cout << cost(low) << '\n';
}

int main(){
	IOS;
	int test = 1;
	while(test--)
		solve();
	return 0;
}






