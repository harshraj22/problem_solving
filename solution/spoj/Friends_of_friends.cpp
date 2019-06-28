#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp set<ll> 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);		cout.tie(0);
ll test=1;
// cin>>test;
while(test--){
	ll i,j,k,n,m=0;
	cin>>n;
	unordered_map<ll,mp> look_up;
	for(i=0;i<n;i++){
		cin>>j;
		cin>>k;
		for(m=0;m<k;m++){
			ll var;
			cin>>var;
			look_up[j].insert(var);
		}
	}
	set<ll> sta;
	for(auto it1:look_up){
		for(auto it2:it1.second){//it2 is id of friends of bob's friends
			if(look_up.find(it2)==look_up.end()){
				sta.insert(it2);
			}
		}
	}
	cout<<sta.size()<<"\n";
}
	return 0;
}