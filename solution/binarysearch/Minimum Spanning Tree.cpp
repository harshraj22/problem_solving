// https://binarysearch.com/problems/Minimum-Spanning-Tree
// check weight of mst same when (a, b) is, to the best mst

int n_nodes = 100000+2;
vector<int> par(n_nodes), rank(n_nodes, 1);

// init dsu
void init_dsu() {
    for (int i = 0; i < par.size(); i += 1)
        par[i] = i;
}

int find_par(int u) {
    if (u == par[u])
        return u;
    return par[u] = find_par(par[u]);
}

bool merge(int u, int v) {
    u = find_par(u);
    v = find_par(v);

    if (u == v) return false;
    par[u] = v;
    return true;
}

int solve1(vector<vector<int>>& edges, int a, int b) {
    init_dsu();
    merge(a, b);
    // sort edges
    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) { return a.back() < b.back(); });

    int weight = 0;
    // merge the edges
    for (auto edge: edges) {
        if (merge(edge[0], edge[1]))
            weight += edge.back();
        else if (a == edge[0] && b == edge[1])
            weight += edge.back();
    }

    return weight;
}

bool solve(vector<vector<int>>& edges, int a, int b) {
    return solve1(edges, a, b) == solve1(edges, 0, 0);
}