Problem: 
   - [Day 27](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3342/)

Tried: 
   - Used `Bipertite matching` of graphs

```c++
class Solution {
	vector<vector<int>> graph;
	vector<int> color;
	int n;  bool possible;

	void dfs(int node, int col, int par=-1) {
		if (color[node] != -1) {
			possible = (color[node] == col)? possible: false;
			return;
		}

		color[node] = col;

		for (auto child: graph[node]) {
			if (child == par) continue;
			dfs(child, 1-col, node);
		}
	}

public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		n = N; graph.resize(n+1);
		color.resize(n+1);  possible = true;
		fill(color.begin(), color.end(), -1);

		// build the graph
		for (auto edge: dislikes) {
			int u = edge[0], v = edge[1];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}	

		// check bipertite matching
		for (int i = 1; i < n; i += 1) {
			if (color[i] == -1)
				dfs(i, 1);
		}

		return possible;
    }
};
```