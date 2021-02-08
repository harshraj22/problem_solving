// https://binarysearch.com/problems/Shipping-and-Receiving

#define all(x) x.begin(), x.end()

int solve(vector<vector<int>>& ports, vector<vector<int>>& shipments) {
    const int inf = 1e7;
    int n = ports.size();

    vector<vector<int>> dist(n, vector<int>(n, inf));

    // initialize the dist
    for (int i = 0; i < n; i += 1) {
        int u = i;
        for (auto v: ports[u]) 
            dist[u][v] = 1;
        dist[u][u] = 0;
    }

    // apply floyd warshall
    for (int k = 0; k < n; k += 1) {
        for (int u = 0; u < n; u += 1) {
            for (int v = 0; v < n; v += 1) {
                if (dist[u][v] > dist[u][k] + dist[k][v])
                    dist[u][v] = dist[u][k] + dist[k][v];
            }
        }
    }

    // return the cost
    int total_cost = 0;
    for (auto edge: shipments) {
        int u = edge[0], v = edge[1];
        if (dist[u][v] < inf)
            total_cost += dist[u][v];
    }

    return total_cost;
    
}