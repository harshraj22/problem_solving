// finally seems solved. Credits for finding lca using binary lifting goes to
// ashishgup github library.
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define eb emplace_back
const int N=300009;
const int LG=log2(N)+1;
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define ROOT 1
int tim=0,n;
ll parent[LG][N];
ll tin[N], tout[N], level[N],twin_prod[N],away_node[N],sum_pass[N];
vector<ll> g[N];

void dfs(int k=ROOT, int par=0, int lvl=1){
	tin[k]=++tim;
	parent[0][k]=par;
	level[k]=lvl;
	for(auto it:g[k]){
		if(it==par)
			continue;
		dfs(it, k, lvl+1);

		ll var=1+away_node[it];
		twin_prod[k]+=var*away_node[k];
		away_node[k]+=var;
	}
	tout[k]=tim;
}

void ek_dfs(int node=1,int par=-1){//ek baar check karle
	if(par!=-1){
		ll var=away_node[node]+1;
		ll sum=(away_node[par]-var)+(twin_prod[par]-var*(away_node[par]-var));
		sum_pass[node]=sum_pass[par]+sum;
	}
	for(auto it:g[node]){
		if(it==par)
			continue;
		ek_dfs(it,node);
	}
}

int walk(int u, int h){
	for(int i=LG-1;i>=0;i--){
		if((h>>i) & 1)
			u = parent[i][u];
	}
	return u;
}

void precompute(){
	for(int i=1;i<LG;i++)
		for(int j=1;j<=n;j++)
			if(parent[i-1][j])
				parent[i][j]=parent[i-1][parent[i-1][j]];
}

int LCA(int u, int v){
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--){
		if((1<<i) & diff){
			u=parent[i][u];
		}
	}
	if(u==v)
		return u;
	for(int i=LG-1;i>=0;i--){
		if(parent[i][u] && parent[i][u]!=parent[i][v]){
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	return parent[0][u];
}

void do_clear(){
	for(auto& it:g)
		it.clear();
	memset(tin,0,sizeof(tin));
	memset(tout,0,sizeof(tout));
	memset(level,0,sizeof(level));
	memset(parent,0,sizeof(parent));
	memset(twin_prod,0,sizeof(twin_prod));
	memset(away_node,0,sizeof(away_node));
	memset(sum_pass,0,sizeof(sum_pass));

	tim=0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
int test;
cin>>test;
while(test--){
	do_clear();
	int i,j,k,m,q;
	cin>>n>>q;
	for(i=1;i<n;i++){
		cin>>j>>k;
		g[j].eb(k);	g[k].eb(j);
	}
	dfs(1,0,1);	precompute();	ek_dfs();
	while(q--){
		ll u,v;
		cin>>u>>v;
/*-----*/if(u==v){//manage separately
			ll val=(n-away_node[u]-1);
			ll sum=away_node[u]+twin_prod[u]+1+val+val*(away_node[u]);
			cout<<sum<<"\n";
			continue;
		}

		ll lc=LCA(u,v);
		if(lc==u || lc==v){
			if(lc==v)swap(u,v);//now lca is u
			ll sum=sum_pass[v]-sum_pass[u];//path passing through
			sum+=away_node[v]+twin_prod[v];//for leaf node
			sum+=level[v]-level[u]+1;//for one node path

/*			watch(sum);watch(sum_pass[u]);watch(sum_pass[v]);
			watch(u);watch(v);*/

			ll target=walk(v,level[v]-level[u]-1);
			ll val=away_node[target];
			
			sum+=(n-away_node[u]-1)*(1+ (away_node[u]-away_node[target]-1));
			cout<<sum<<"\n";
			// cout<<target<<" is the target node \n";
		}
		else {
			ll sum=sum_pass[v]-sum_pass[lc];//path passing through
			sum+=away_node[v]+twin_prod[v];//for leaf node
			sum+=level[v]-level[lc]+1;//for one to one
			ll tar1=walk(v,level[v]-level[lc]-1);
			ll var1=away_node[tar1]+1;

			sum+=sum_pass[u]-sum_pass[lc];
			sum+=away_node[u]+twin_prod[u];
			sum+=level[u]-level[lc];
			ll tar2=walk(u,level[u]-level[lc]-1);
			ll var2=away_node[tar2]+1;

			sum-=sum_pass[tar1]-sum_pass[lc];
			sum-=sum_pass[tar2]-sum_pass[lc];

			// cout<<sum<<" is sum for now \n";

			ll val=(away_node[lc]-var1-var2);//(a+b+c+d)-c-d
			ll par=(n-away_node[lc]-1);

			sum+=val+par+(twin_prod[lc]-val*(var1+var2)-var1*var2)+par*val;
			cout<<sum<<"\n";

		}
	}
}
	return 0;
}