// https://codeforces.com/problemset/problem/1093/D

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
const int mod = 998244353;
bool possible = true;
vector<vector<int>> graph;
vector<int> visited;
int Count[2];

ll inline power(ll x, ll y, ll mod = 1e9+7){
	ll res = 1;
	while(y > 0){
		if(y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x*x)% mod;
	}
	return res % mod;
}

void dfs(int node, int par, int parity) {
	if (visited[node] != -1) {
		possible = (visited[node] != parity) ? false: possible;
		return ;
	}

	Count[parity] += 1;
	visited[node] = parity;
	for (auto child: graph[node]) {
		if (child != par)
			dfs(child, node, 1-parity);
	}
}

void solve(){
	possible = true;
	Count[1] = Count[0] = 0;
	int n, m;	cin >> n >> m;
	graph.resize(n+1); visited.resize(n+1);
	fill(visited.begin(), visited.end(), -1);
	for (auto &it: graph) it.clear();

	for (int i = 0; i < m; i += 1) {
		int u, v;	cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	long long int ans = 1;
	for (int i = 1; i <= n; i += 1) {
		if (visited[i] == -1) {
			Count[0] = Count[1] = 0;
			dfs(i, -1, 1);
			ans *= (power(2, Count[0], mod) + power(2, Count[1], mod)) % mod;
			ans %= mod;
		}
	}

	// dfs(1, -1, 1);
	if (!possible) {
		cout << 0 << '\n';
		return;
	}

	// do the power over mod and print the answer
	cout << ans % mod << '\n';

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test = 1;
	cin >> test;
	while(test--)
		solve();
	return 0;
}