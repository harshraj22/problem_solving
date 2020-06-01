// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

/*  
Cycle Detection in Directed Graph is different from that in undirected graph.
There might be two paths from one node two another, which is considered a cycle
if graph is undirected, but not a cycle if graph is directed.

Idea is to have 3 states for each node:
0. Not discovered (node never came while dfs)
1. Discovered but not completed (node entered dfs but didn't exit, recursive call to child)
2. Completed visit (node entered dfs, recuresed to child, and exited)

If a node visits a discovered but not completed node, then there is a cycle
Some people also know these using concepts like back edges.
*/

/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

void dfs(vector<int> adj[], int v, int node, vector<int> &vis, bool &hasCycle) {
    vis[node] = 1;  // Discovered but not visited
    for (auto child: adj[node]) {
        if (vis[child] == 1)
            hasCycle = true;
        else 
            dfs(adj, v, child, vis, hasCycle);
    }

    vis[node] = 2;  // complete visit
}

bool isCyclic(int v, vector<int> adj[]) {
    bool hasCycle = false;
    vector<int> vis(v+1, 0);

    for (int i = 0; i < v; i += 1) {
        if (!vis[i]) 
            dfs(adj, v, i, vis, hasCycle);
    }

    return hasCycle;
}

