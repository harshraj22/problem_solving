// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/

/*
*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

void dfs(vector<int> &g[], int v, int node, int par, vector<bool> &vis, bool &hasCycle) {
    vis[node] = true;
    for (auto child: g[node]) {
        if (child == par) 
            continue;
        else if (vis[child])
            hasCycle = true;
        dfs(g, v, child, node, vis, hasCycle);
    }
}

bool isCyclic(vector<int> g[], int v) {
    vector<bool> visited(v, false);
    bool hasCycle = false;

    for (int i = 0; i < v; i += 1) {
        if (!visited[i]) 
            dfs(g, v, i, -1, visited, hasCycle);
    }
   
    return hasCycle;
}