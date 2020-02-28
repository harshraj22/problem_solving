/*
	https://www.spoj.com/problems/PT07Z/
	Remember: Every tree is not a binary tree.
    Easy DFS with storing result for each node (Can be considered as dp on trees)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

ll power(ll x, ll y, ll mod){
	ll res = 1;
	while(y > 0){
		if(y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x*x)% mod;
	}
	return res % mod;
}

const ll mod = 1e9+9;
int n;
vector<vector<int> > tree;
// {max_depth, answer if current node is included in longest path}
vector<ll> dp,ans;

void dfs(int node, int par = -1){
	dp[node] = 1;
	ans[node] = 1;
	vector<ll> mx;

	for(auto child:tree[node]){
		if(child == par)
			continue;
		dfs(child,node);
		dp[node] = max(dp[node], dp[child] + 1);

		mx.push_back(dp[child]);
	}

	// take max 2 subtree to be included in longest path including current node
	sort(mx.begin(),mx.end(),greater<ll>());
	for(int i=0;i<min(2,(int)mx.size()); i++){
		ans[node] += mx[i];
	}
}

void solve(){
	cin >> n;
	tree.resize(n+1);
	dp.resize(n+1);	ans.resize(n+1);
	fill(dp.begin(),dp.end(),0);
	fill(ans.begin(),ans.end(),0);

	for(int i=1;i<n;i++){
		int u,v;	cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	int root = 1;
	dfs(root);

	cout << *max_element(ans.begin(),ans.end()) -1 << '\n';
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
