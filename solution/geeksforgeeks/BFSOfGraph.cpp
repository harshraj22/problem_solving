// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {
    vector<bool> visited(N, false);
    queue<int> q = {0};
    visited[0] = true;
    vector<int> order;  order.reserve(N);

    while (!q.empty()) {
        int cur = q.front();
        order.push_back(cur);
        q.pop();
        for (auto child: g[cur]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }

    return order;
}