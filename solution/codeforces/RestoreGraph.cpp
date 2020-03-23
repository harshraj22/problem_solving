/*
    See {editor_snippets} for this template for vs code.
    problem: https://codeforces.com/problemset/problem/404/C
    idea: 
        we create a tree, 
*/

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
#define pi pair<ll,ll>

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

bool notPossible() {
	cout << -1 << '\n';
	return false;
}

bool check(auto &graph, int n, int k) {
    // checks the graph we built is correct solution or not

	int edges = 0;
	for (int i=1;i<=n;i++) {
		if (graph[i].size() > k) 
			return notPossible();
		edges += graph[i].size();
	}

    // we tried to build a tree.
	if (edges != n-1)
		return notPossible();

	cout << edges << '\n';
	
	for (int i=1;i<=n;i++) {
		for (auto it:graph[i])
			cout << i << ' ' << it << '\n';
	}

	return true;
}

bool solve(){
	int n,k;	cin >> n >> k;
	// dist[i] stores nodes which are at 'i' distance from root
	vector<int> dist[n];

	// Store data in proper format
	for (int i=0;i<n;i++) {
		int var;	cin >> var;
		dist[var].push_back(i+1);
	}

	// build graph
	vector<vector<int>> graph(n+1);
	vector<int> degree(n+1,0);
	int lastSize = 1;

	for (int i=1;i<n;i++) {
		if (dist[i].empty())
			break;
		lastSize = dist[i-1].size();

        // if there was no node at distance 'i-1' there cant be a node at distance 'i'
		if (lastSize == 0)
			return notPossible();

		int parent = 0;
		for (auto child:dist[i]) {
			graph[dist[i-1][parent]].push_back(child);

			degree[dist[i-1][parent]] += 1;
			degree[child] += 1;
			parent = (parent+1)%lastSize;
		}
	}

    // if there are >1 or 0 nodes at distance 0, it isn't possible
	if (dist[0].size() != 1) 
		return notPossible();

	if (*max_element(degree.begin(), degree.end()) > k)
		return notPossible();

	return check(graph, n, k);
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