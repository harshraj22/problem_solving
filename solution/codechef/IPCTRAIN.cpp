// https://www.codechef.com/JULY17/problems/IPCTRAIN
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define mp make_pair

// For each day, give class to that prof which has highest sadness level (use priority queue for this)

void solve(){
	ll n,d,i;
	cin >> n >> d;
	map<int,vector<pi> > _map;	// day => <sadness, num of days>
	for(int i=0;i<n;i++){
		int di, ti, si;
		cin >> di >> ti >> si;
		_map[di].push_back(mp(si, ti));
	}
	ll sadness = 0;
	priority_queue<pi, vector<pi> > pq;
	for(int day=1;day <=d;day++){
		for(auto temp:_map[day]){
			pq.push(temp);
		}
		if(pq.empty() == false){
			pi saddest = pq.top();
			pq.pop();
			
			if(saddest.second > 1){
				pq.push(mp(saddest.first, saddest.second - 1));
			}
		}
	}
	while(pq.empty() == false){
		pi sad = pq.top();
		pq.pop();
		sadness += sad.first*sad.second;
	}

	cout << sadness << '\n';

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin >> test;
	while (test--)
		solve();

	return 0;
}