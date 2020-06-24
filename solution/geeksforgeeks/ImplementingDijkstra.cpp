// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
vector <int> dijkstra(vector<vector<int>> g, int src, int v) {
    int inf = 1e7;
    vector<int> dist(v, inf);
    vector<vector<pair<int, int>>> graph(v);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < v; i += 1) {
        for (int j = 0; j < v; j += 1) {
            if (g[i][j] > 0) 
                graph[i].push_back({j, g[i][j]});
        }
    }

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int wt = it.first, u = it.second;

        for (auto edge: graph[u]) {
            int v1 = edge.first, dst = edge.second;
            if (dist[v1] > dist[u] + dst) {
                dist[v1] = dist[u] + dst;
                pq.push({dist[v1], v1});
            }
        }
    }

    return dist;
}


