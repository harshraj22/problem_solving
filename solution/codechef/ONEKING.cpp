// idea from editorial
// https://www.codechef.com/problems/ONEKING

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
const int N=2002;

bool comparator(pi a, pi b){
	if(b.second > a.second)
		return true;
	else if(b.second < a.second)
		return false;
	return b.first > a.first;
}

void solve(){
	int n;
	cin >> n;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), comparator);
	
	int ans=0,ls=-1;
	vector<int> last(N,-1);
	for(int i=0;i<n;i++){
		// v[i] stores the max starting point out of all ranges that end at i
		last[v[i].second] = max(last[v[i].second], v[i].first);
	}

	// this iteration should be identified as sweep line
	for(int i=0;i<n;i++){
		if(last[v[i].second] > ls){
			// this should be identified as two pointer, the first points to the range being checked to be deleted
			// while the second points to the rightmost element of last deleted range
			ls = v[i].second;
			ans += 1;
		}
	}

	cout << ans << "\n";
}

int main(){
	int test;
	cin >> test;
	while(test--)
		solve();

	return 0;
}