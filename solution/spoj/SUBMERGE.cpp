// https://www.spoj.com/problems/SUBMERGE/
// Articulation points: https://codeforces.com/blog/entry/71146

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

int n, m, Time;
vector<vector<int>> graph;
// low[i] stores the min disovery time of nodes reachable 
// by the dfs tree from i
vector<int> art_pt, disc, low;

void init() {
    Time = 0;

    graph.resize(n+1);
    for (auto &it: graph)
        it.clear();

    art_pt.resize(n+1);
    fill(art_pt.begin(), art_pt.end(), 0);

    disc.resize(n+1);
    fill(disc.begin(), disc.end(), 0);

    low.resize(n+1);
    fill(low.begin(), low.end(), 0);
}

int dfs(int node, int par=-1) {
    low[node] = disc[node] = ++Time;
    int children = 0;

    for (auto child: graph[node]) {
        if (child == par) continue;
        if (!disc[child]) {
            // if child is not visited
            dfs(child, node);
            children += 1; 
            if (disc[node] <= low[child])
                art_pt[node] = 1;
            low[node] = min(low[node], low[child]);
        }
        else {
            // if child was already visited, we found an ancestor
            low[node] = min(low[node], disc[child]);
        }
    }

    return children;
}

void solve(){
    init();    
    for (int i = 0; i < m; i += 1) {
        int u, v;   cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i += 1) {
        if (!disc[i]) {
            // for root of dfs tree, check if it has
            // 2 or more disconnected childrent
            art_pt[i] = (dfs(i) > 1);
        }
    }

    // do other calculations and print result
    cout << accumulate(art_pt.begin(), art_pt.end(), 0) << '\n';

    cin >> n >> m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    int test = 1;
    // cin >> test;
    cin >> n >> m;
    while(n || m)
        solve();
    return 0;
}