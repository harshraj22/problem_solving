// https://www.codechef.com/COW42020/problems/COW3D
// Finding LCA using binary lifting 

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
const int N = 2e5 + 5;
int lg = log2(N) + 1;

vector<vector<int>> tree, parent(N, vector<int> (lg, 0));
vector<int> depth(N, 0);
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
    for (int i = lg; i >= 0; i -= 1) {
        if (parent[node1][i] == parent[node2][i])
            continue;
        node1 = parent[node1][i];
        node2 = parent[node2][i];
    }

    return parent[node1][0];
}

void solve(){
    cin >> n >> q;
    tree.resize(n+1);
    for (int i = 1; i < n; i += 1) {
        int u, v;   cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    while (q-- ) {
        int k;  cin >> k;
        vector<int> nodes(k);
        for (auto &it: nodes)
            cin >> it;
        int L = nodes[0];
        if (k > 1) {
            for (auto node: nodes) 
                L = lca(L, node);
        }
        
        if (find(nodes.begin(), nodes.end(), L) == nodes.end())
            L = -1;

        cout << L << '\n';
    }
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