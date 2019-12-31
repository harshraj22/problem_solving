// dp on trees (easy)
// https://codeforces.com/problemset/problem/682/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 0x3f3f3f3f
#define pi pair<ll,ll>
#define mp make_pair
#define eb emplace_back

#define deb(x) cerr << #x << " = " << x << endl;
const ll N=1e5+5;

ll n,ans=0;
vector<pi> g[N];
vector<int> val(N),dep(N);

void dfs(int node,int par){
	for(auto it:g[node]){
		if(it.first==par)continue;
		dfs(it.first,node);
		dep[node]+=dep[it.first];
	}
	dep[node]+=1;
}

void dfs2(int node,int par,ll dist){
	// cout<<"at node with : "<<node<<" "<<dist<<endl;
	if(dist>val[node]){
		ans+=dep[node];
		return;
	}
	for(auto it:g[node]){
		if(it.first==par)continue;
		dfs2(it.first,node,max(dist+it.second,it.second));
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>val[i];
	for(int i=1;i<n;i++){
		int p,c;
		cin>>p>>c;
		g[i+1].eb(mp(p,c));
		g[p].eb(mp(i+1,c));
	}
	dfs(1,0);
	dfs2(1,0,INT_MIN);
	cout<<ans<<"\n";
	return 0;
}
