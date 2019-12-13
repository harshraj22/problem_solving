// https://www.codechef.com/ICPCIN19/problems/SEGDIR/

#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long int ll;
#define pi pair<int , int>
const int inf = 0x3f3f3f3f;
#define endl '\n'
using namespace std;



int main(){
	fastio
	int test;
	cin >> test;
	while(test--){
		ll n;
		cin >> n;
		map<ll , vector <pair<ll , ll> > >mp;
		for(int i=0;i<n;i++){
			ll li,ri,vi;
			cin >> li >> ri >> vi;
			mp[vi].emplace_back(make_pair(li , ri));
		}

		bool ans = true;
		for(auto &vel : mp){
			sort(vel.second.begin() , vel.second.end());
			// vel.second = vector(pair)
			for(int i=0;i<vel.second.size();i++){
				ll l = vel.second[i].first,r = vel.second[i].second;
				ll count=1;
				pair<ll ,ll>inter = {l , r};
				for(int j=i+1;j<vel.second.size();j++){
					ll rf = vel.second[j].second; 
					ll lf = vel.second[j].first;
					if(lf <= inter.second &&  rf >= inter.first){
						inter.first = max(inter.first , lf);
						inter.second = min(inter.second , rf);
						++count;
					}
					else{
						inter = make_pair(lf , min(rf , r));
						count = 2;
						if(lf  > r){
							break;
						}
					}

					if(count >= 3){
						ans = false;
						j = n+3;
						i = n+3;
					}
				}
			}
		}
		if(ans){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}