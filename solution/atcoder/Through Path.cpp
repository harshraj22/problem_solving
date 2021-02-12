// https://atcoder.jp/contests/abc187/tasks/abc187_e
// Finding LCA using binary lifting 

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
const int N = 2e5 + 5;
int lg = log2(N) + 1;

vector<vector<int>> tree, parent(N, vector<int> (lg, 0));
vector<ll> depth(N, 0), diffs;
int n, q;

bool isSet(int bit, int num) {
    return num & (1 << bit);
}

// pre-calculation step, parent[node][i] stores the power(2, i)th parent of 'node'
void dfs(int node, int par = 0, int height = 0) {
    parent[node][0] = par;
    depth[node] = height;
    for (int i = 1; i < parent[node].size(); i += 1) {
        int var = parent[node][i-1];
        parent[node][i] = parent[var][i-1];
    }

    for (auto child: tree[node]) {
        if (child != par)
            dfs(child, node, height+1);
    }
}

int lca(int node1, int node2) {
    if (depth[node2] > depth[node1])
        swap(node1, node2);
    // now depth[node1] >= depth[node2]
    int dist = depth[node1] - depth[node2];

    // Jump node1 upwards until depth[node1] != depth[node2]
    // consider the binary form of 'dist' for better understanding
    for (int i = 31; i >= 0; i -= 1) {
        if (isSet(i, dist)) {
            node1 = parent[node1][i];
        }
    }

    if (node1 == node2)
        return node1;
    else if (node1 == 1 || node2 == 1)
        return 1;

    // now node2 and node1 are on the same level
    // While they both don't share same parent, keep jumping up
    // note we are iterating from 31-1 and not from 1-31
    // the former gives log(n) time while the later O(n)
    // Again consider the binary form of depth[lca] - depth[node1] for understanding
    for (int i = lg-1; i >= 0; i -= 1) {
        if (parent[node1][i] == parent[node2][i])
            continue;
        node1 = parent[node1][i];
        node2 = parent[node2][i];
    }

    return parent[node1][0];
}

void dfs2(int node, int par, ll carry) {
	carry += diffs[node];
	diffs[node] = carry;

	for (auto child: tree[node]) {
		if (child == par)
			continue;
		dfs2(child, node, carry);
	}
}

void solve(){
    cin >> n;
    tree.resize(n+2);
    diffs.resize(n+2);

    vector<int> a(n), b(n);
    for (int i = 1; i < n; i += 1) {
        int u, v;   cin >> u >> v;
        a[i] = u;	b[i] = v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int root = 1;
    // for (int i = 1; i <= n; i += 1)
    // 	if (tree[i].)
    dfs(root);
    cin >> q;

    while (q-- ) {
    	ll t, e, x, u, v;
    	cin >> t >> e >> x;

    	if (a[e] == b[e])
    		continue;

		// from u without v
    	if (t == 1) {
    		u = a[e], v = b[e];
    	} else {
    		u = b[e];	v = a[e];
    	}

    	// cerr << "Trace u, v: " << u << ' ' << v << '\n';

    	if (lca(u, v) != v) {
    		// add to root
    		diffs[root] += x;

    		// put diff in subtree-b
    		diffs[v] -= x;
    	}

    	else if (parent[u][0] == v) { // v is parent of u
    		diffs[u] += x;
    	}

    	else {
    		// put diff at root
    		// diffs[root] -= x;

    		// add to childrent of b
    		for (auto child: tree[v]) {
    			if (lca(child, v) == v)
    				diffs[child] += x;
    		}
    	}
    }

    dfs2(root, -1, 0);

    for (int i = 1; i <= n; i += 1)
    	cout << diffs[i] << '\n';
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
