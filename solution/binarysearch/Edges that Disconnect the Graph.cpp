vector<bool> visited;
vector<int> tin, low;
int timer;
int n; // number of nodes
vector<vector<int>> adj;
int cnt;

void IS_BRIDGE(int v, int to) {
    cnt += 1;
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

int solve(vector<vector<int>>& graph) {
    adj = graph;
    n = graph.size();
    cnt = 0;
    visited = vector<bool> (n, false);
    tin = vector<int> (n, 0);
    low = vector<int> (n, 0);

    find_bridges();

    return cnt;   
}
