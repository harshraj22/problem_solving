// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1246
// Basic Topological Sort

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> indegree, ans;

void dfs(int node) {
    ans.push_back(node);
    for (auto child:graph[node]) {
        indegree[child] -= 1;
        if (indegree[child] == 0)
            dfs(child);
    }
    indegree[node] = -2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n = 1, m = 1;
    cin >> n >> m;
    while(n || m) {
        graph.resize(n+1, vector<int>());
        for (auto &it: graph) it.clear();
        indegree.resize(n+1, 0);
        fill(indegree.begin(), indegree.end(), 0);
        ans.clear();

        for (int i = 0; i < m; i += 1) {
            int u, v;   cin >> u >> v;
            // u must be executed before v
            graph[u].push_back(v);
            indegree[v] += 1;
        }

        for (int i = 1; i <= n; i += 1) {
            if (indegree[i] == 0)
                dfs(i);
        }

        for (auto it:ans)  cout << it << ' ';
            cout << '\n';

        cin >> n >> m;
    }

    return 0;
}