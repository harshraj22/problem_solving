// https://practice.geeksforgeeks.org/problems/topological-sort/1/?track=ppc-graph&batchId=221

// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/

// standard problem based on Topological Sort
void dfs(int node, int par, vector<int> adj[], vector<int> &indegree, vector<int> &topo) {
    indegree[node] -= 1;
    for (auto child: adj[node]) {
        indegree[child] -= 1;
        if (indegree[child] == 0) {
            topo.push_back(child);
            dfs(child, node, adj, indegree, topo);
        }
    }
}

vector<int> topoSort(int v, vector<int> adj[]) {
    vector<int> indegree(v, 0);
    vector<int> topo;
    
    for (int i = 0; i < v; i += 1) {
        for (auto child: adj[i])
            indegree[child] += 1;
    }
    
    for (int i = 0; i < v; i += 1) {
        if (indegree[i] == 0) {
            topo.push_back(i);
            dfs(i, -1, adj, indegree, topo);
        }
    }
    
    return topo;
}