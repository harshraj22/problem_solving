// https://www.hackerearth.com/problem/algorithm/dijkstras/description/
// Note: Use c++17 for compiling

#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &graph, int src, int dst) {
	int n = graph.size(), inf = 1e7;
	vector<int> cost(n, inf), next(n);
	cost[src] = 0;	next[src] = -1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, src});

	while (!pq.empty()) {
		auto [d, node] = pq.top();
		pq.pop();
		for (auto [v, wt]: graph[node]) {
			if (cost[v] > d + wt) {
				cost[v] = d + wt;
				next[v] = node;
				pq.push({cost[v], v});
			}
		}
	}

	cout << cost[dst] << '\n';
	stack<int> stk;
	while (dst != -1) {
		stk.push(dst);
		dst = next[dst];
	}
	
	while (!stk.empty()) {
		cout << stk.top() << ' ';
		stk.pop();
	}

	cout << endl;
}

void solve() {
	int n; 	cin >> n;
	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < n; j += 1) {
			int wt;	cin >> wt;
			if (wt == 0)
				continue;
			graph[i].push_back({j, wt});
			graph[j].push_back({i, wt});
		}
	}

	int src, dst;	cin >> src >> dst;
	dijkstra(graph, src, dst);
}

int main() {
	int test;	cin >> test;
	while (test--)
		solve();

	return 0;
}
