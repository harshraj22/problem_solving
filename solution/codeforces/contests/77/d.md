* Upsolve using editorial
``` c++
// help from editorial

//=====================COMPILER OPTIMIZATION STARTS=======================
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//======================COMPILER OPTIMIZATION ENDS=======================

//compile using : g++ -D DEB file.cpp
#ifdef DEB
    //to check from out of bounds errors
    #define _GLIBCXX_DEBUG
#endif
//=============================DEBUG PART ENDS===========================

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int, int>

ll power(ll x, ll y, ll mod = 1e9+7){
    ll res = 1;
    while(y > 0){
        if(y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x*x)% mod;
    }
    return res % mod;
}

void solve(){
	int numOfSol, numOfPoints, numOfTraps, maxTime;
	cin >> numOfSol >> numOfPoints >> numOfTraps >> maxTime;

	vector<int> agility(numOfSol, 0);
	for (auto &it:agility)
		cin >> it;

	// base case when no one can be taken due to low maxTime
	if (maxTime < numOfPoints) {
		cout << 0 << '\n';
		return;
	}
	
	vector<int> initial(numOfTraps, 0), end(numOfTraps, 0), danger(numOfTraps, 0);
	
	for (int i = 0; i < numOfTraps; i += 1) {
		cin >> initial[i] >> end[i] >> danger[i];
	}

	int low = 0, high = 2e5+5;

	auto possible = [&](int mid)->bool {
		vector<pi> segments;
		for (int i = 0; i < numOfTraps; i += 1) {
			if (danger[i] > mid) 
				segments.push_back({initial[i], end[i]});
		}

		sort(segments.begin(), segments.end());

		int time = 0, position = 0;
		for (auto it:segments) {
			if (it.second <= position)
				continue;
			else if (it.first <= position) {
				time += max(it.second - position, 0);
				position = max(it.second, position);
			}	
			else if (it.first > position) {
				time += 1 + it.second - it.first;
				position = it.second;
			}
		}


		return time*2 + numOfPoints + 1 <= maxTime;
	};

	while(low < high) {
		int mid = (high+low)/2;
		if (possible(mid))
			high = mid;
		else 
			low = mid + 1;
	}

	cout << count_if(agility.begin(), agility.end(), [&](int agi){return agi >= low;}) << '\n';
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
```