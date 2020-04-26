// https://codeforces.com/problemset/problem/489/D

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

vector<vector<int>> graph, table;
int n, m, ans = 0;

void dfs(int node, int par) {
    for (auto child: graph[node]) {
        if (par != child) {
            table[par][child] += 1;
        }
    }
}

void solve(){
    cin >> n >> m;    
    graph.resize(n+1);
    table.resize(n+1, vector<int>(n+1));
    for (auto &row: table) {
        for (auto &ele: row)
            ele = 0;
    }

    for (int i = 0; i < m; i += 1) {
        int a, b;   cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int node = 1; node <= n; node += 1) {
        for (auto child: graph[node]) 
            dfs(child, node);
    }

    int ans = 0;
    for (int i = 0; i <= n; i += 1) {
        for (int j = 0; j <= n; j += 1) {
            long long int a = table[i][j];
            ans += (a*(a-1))/2;
        }
    }

    cout << ans << '\n';
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