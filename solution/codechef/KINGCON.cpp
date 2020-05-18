// https://www.codechef.com/problems/KINGCON
// Articulation points: https://codeforces.com/blog/entry/71146

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

vector<vector<int>> graph;
vector<int> art, disc, low;
int Time, n, m, k;

void init() {
    Time = 0;

    graph.resize(n+1);
    for (auto &it: graph)
        it.clear();
    
    art.resize(n+1);
    fill(art.begin(), art.end(), 0);

    low.reserve(n+1);
    fill(low.begin(), low.end(), 0);

    disc.resize(n+1);
    fill(disc.begin(), disc.end(), 0);
}

int dfs(int node, int par=-1) {
    low[node] = disc[node] = ++Time;
    int children = 0;
    for (auto child: graph[node]) {
        if (child == par) continue;
        if (!disc[child]) {
            children += 1;
            dfs(child, node);
            if (disc[node] <= low[child])
                art[node] = 1;
            low[node] = min(low[node], low[child]);
        }
        else {
            low[node] = min(low[node], disc[child]);
        }
    }

    return children;
}

void solve(){
    cin >> n >> m >> k; init();
    for (int i = 0; i < m; i += 1) {
        int u, v;   cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i += 1) {
        if (!disc[i]) {
            art[i] = (dfs(i) > 1);
        }
    }

    ll ans = accumulate(art.begin(), art.end(), 0);
    cout << ans * k << '\n';
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