// https://codeforces.com/problemset/problem/400/D

#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pi pair<int,int>

struct edge{
	ll u = 0, v = 0, x = 0;
};

int n, m, k;
// c: standard arry of input
// typeArea: array containing partial sum of array c, used in determining
// 			type of an element in log(n)
vector<ll> c, typeArea;
vector<edge> edges;

int type(int val) {
	return 1 + lower_bound(typeArea.begin(), typeArea.end(), val) - typeArea.begin();
}

vector<int> par, Rank;

int findPar(int node) {
	if (par[node] == node)
		return node;
	return par[node] = findPar(par[node]);
}

void Join(int u, int v) {
	u = findPar(u);
	v = findPar(v);

	if (Rank[u] > Rank[v]) {
		par[v] = u;
		Rank[u] += Rank[v];
	}	else {
		par[u] = v;
		Rank[v] += Rank[u];
	}
}

bool isTypeCorrect() {
	par.resize(n+1);
	iota(par.begin(), par.end(), 0);
	Rank.resize(n+1);
	fill(Rank.begin(), Rank.end(), 1);

	map<pi, int> mp;

	for (auto e: edges) {
		if (type(e.u) == type(e.v) && e.x == 0) {
			// if there is an edge of 0 weight connecting
			// nodes of same type, merge then using DSU
			Join(e.u, e.v);
		}	
		else if (e.x == 0) {
			// if there is a 0 weight edge, connecting nodes of 
			// two different type, store this, and use it later 
			// if any other node (of same type) with 0 edge weight
			//  connects to this node
			int tu = type(e.u), tv = type(e.v);

			// use mapping of (node, type) => node
			if (mp.find({e.v, tu}) == mp.end() && mp.find({e.u, tv}) == mp.end()) {
				mp[{e.u, tv}] = e.v;
				mp[{e.v, tu}] = e.u;
			}
			else if (mp.find({e.v, tu}) != mp.end()) {
				// if there was already a node of type 'tu'
				// connecting to node 'e.v' with weight 0, 
				// (remember type(e.v) != tu, type(e.u) == tu)
				// Join the previous node to 'e.u' as we have now
				// a path passing through 'e.v' with 0 weight
				Join(mp[{e.v, tu}], e.u);
			}
			else {
				Join(mp[{e.u, tv}], e.v);
			}
		}
	}

	int uniques = 0;
	for (int i = 1; i < par.size(); i += 1) {
		if (par[i] == i)
			uniques += 1;
	}

	return (uniques == k);
}

void printMin() {
	// build graphs
	vector<vector<ll> > matrix(k+1, vector<ll> (k+1, 1e9));

	for (int i = 0; i <= k; i += 1) {
		// distance between nodes of same type is 0
		// already verified
		matrix[i][i] = 0;
	}

	// fill the distance matrix
	for (auto e:edges) {
		int u = type(e.u), v = type(e.v);
		if(type(e.u) == type(e.v)) {
			matrix[u][v] = 0;
			matrix[v][u] = 0;
		}	else {
			matrix[u][v] = min(matrix[u][v], e.x);
			matrix[v][u] = min(matrix[v][u], e.x);
		}
	}

	// apply floyd-warshal algorithm
	for (int kk = 1; kk <= k; kk += 1) {
		for (int ii = 1; ii <= k; ii += 1) {
			for (int jj = 1; jj <= k; jj += 1) {
				if (matrix[ii][kk] + matrix[kk][jj] < matrix[ii][jj])
					 matrix[ii][jj] = matrix[ii][kk] + matrix[kk][jj];
			}
		}
	}

	for (int i = 1; i <= k; i += 1) {
		for (int j = 1; j <= k; j += 1) {
			if (matrix[i][j] == 1e9)
				matrix[i][j] = -1;
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> n >> m >> k;
	c.resize(k);	typeArea.resize(k);
	edges.resize(m);

	for (auto &it:c)
		cin >> it;
	partial_sum(c.begin(), c.end(), typeArea.begin());

	for (auto &it:edges)
		cin >> it.u >> it.v >> it.x;

	// check if type-distribution is correct
	if (isTypeCorrect()) {
		// find min distances
		cout << "Yes\n";
		printMin();

	}	else {
		cout << "No\n";
	}


	return 0;
}