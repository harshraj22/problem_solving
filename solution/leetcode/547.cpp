// https://leetcode.com/problems/friend-circles/

class Solution {
	vector<vector<int>> graph;
	vector<int> vis;
	int n;

	void dfs(int node) {
		if (vis[node])
			return;
		vis[node] = 1;
		for (auto child: graph[node])
			dfs(child);
	}
public:
    int findCircleNum(vector<vector<int>>& M) {
        n = M.size();
        graph = vector<vector<int>> (n);
        vis = vector<int> (n, 0);

        // create adjecency graph
        for (int i = 0; i < n; i += 1) {
        	for (int j = 0; j < n; j += 1) {
        		if (M[i][j] == 1)
        			graph[i].push_back(j);
        	}
        }

        // count connected components
        int cmp = 0;
        for (int i = 0; i < n; i += 1) {
        	if (!vis[i]) {
        		dfs(i);
        		cmp += 1;
        	}
        }

        return cmp;
    }
};