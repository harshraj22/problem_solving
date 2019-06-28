#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define inf 1LL<<60
#define mp make_pair
#define pi pair<ll,ll>
#define eb emplace_back


int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);		cout.tie(0);
int test;
cin>>test;
while(test--){
	ll i,j,k,n,m,neighbours;
	string s;
	cin>>n;
	vector<vector<pi > >v(n+1);//for graph
	map<string,ll> look_up;//for index-> string
	for(i=1;i<=n;i++){
		cin>>s;
		look_up[s]=i;
		cin>>neighbours;
		while(neighbours--){
			ll index,val;
			cin>>index>>val;//index of its neighbours and weight
			// string var=look_up[index];//string of its neighbour
			v[i].eb(mp(index,val));
			v[index].eb(mp(i,val));
		}
	}
//now dijkstra-----------
	ll no_of_path;
	cin>>no_of_path;
	while(no_of_path--){
		priority_queue<pi,vector<pi>,greater<pi> > pq;
		string source_string,desti_string;
		cin>>source_string>>desti_string;

		ll st=look_up[source_string],en=look_up[desti_string];
		pq.push(mp(0,st));
		vector<ll> dist(n+1,inf);
		dist[st]=0;

		while(pq.empty()==0){
			pi v_var=pq.top();
			pq.pop();
			if(v_var.second==en)
				break;
			for(auto it:v[v_var.second]){
				if(dist[it.first]>dist[v_var.second]+it.second){
					dist[it.first]=dist[v_var.second]+it.second;
					pq.push(mp(dist[it.first],it.first));
				}
			}
		}
		cout<<dist[en]<<"\n";
	}
}
	return 0;
}