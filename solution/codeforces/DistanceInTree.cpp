// https://codeforces.com/problemset/problem/161/D

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

const int N = 5e4 + 2;
const int K = 502;

int dp_child[N][K], dp_par[N][K], n, k;
vector<vector<int> > graph;

void dfs1(int node, int par) {
    // for child subtree
    for (auto child: graph[node]) {
        if (child != par)
            dfs1(child, node);
    }

    dp_child[node][0] = 1;
    // for each possible distance
    for (int i = 1; i <= k; i += 1) {
        dp_child[node][i] = 0;
        for (auto child: graph[node]) {
            if (child != par)
                dp_child[node][i] += dp_child[child][i-1];
        }
    }
}

void dfs2(int node, int par) {
    // all subtree answers have already been calculated

    dp_par[node][0] = 0;

    // for each possible distance
    for (int i = 1; i <= k; i += 1) {
        dp_par[node][i] = max(0, dp_child[par][i-1] + dp_par[par][i-1]);
        if (i-2 >= 0 && dp_child[par][i-1])
            dp_par[node][i] -= dp_child[node][i-2];
    }

    for (auto child: graph[node]) {
        if (child != par)
            dfs2(child, node);
    }
}

void solve(){
    for (int i = 1; i < N; i += 1) {
        for (int j = 1; j < K; j += 1)
            dp_child[i][j] = dp_par[i][j] = 0;
    }

    cin >> n >> k;
    graph.resize(n+1);

    for (int i = 1; i < n; i += 1) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int root = 1;
    dfs1(1, 0);
    dfs2(1, 0);

    long long int ans = 0;
    for (int i = 1; i <= n; i += 1) 
        ans += (dp_child[i][k] + dp_par[i][k]);

    cout << ans/2 << '\n';
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