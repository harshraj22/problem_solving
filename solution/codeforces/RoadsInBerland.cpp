// https://codeforces.com/problemset/problem/25/C

// idea from editorial

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
	int n, k;	cin >> n;
	vector<vector<ll> > dist(n, vector<ll>(n));

	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < n; j += 1)
			cin >> dist[i][j];
	}

	cin >> k;

	for (int i = 0; i < k; i += 1) {
		long long int sum = 0, a, b, c;
		cin >> a >> b >> c;
		a -= 1;	b -= 1;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);

        vector<vector<ll> > dist_ = dist;

		for (int l = 0; l < n; l += 1) {
			for (int r = 0; r < n; r += 1) {
                // for each pair of cities, check if min distance is updated if 
                // newly constructed road is included in the path

                // Note that in case of shortest distance, the newly constructed
                // road can come at max once, so using dist[l][a] instead of dist_[l][a]
                // as it contains min dist when newly constructed road is not considered
				dist_[l][r] = min(dist[l][r], dist[l][a] + dist[a][b] + dist[b][r]);
				dist_[l][r] = min(dist_[l][r], dist[l][b] + dist[b][a] + dist[a][r]);
				if (l < r)
					sum += dist_[l][r];
			}
		}
        dist = dist_;
		cout << sum << ' ';
	}
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