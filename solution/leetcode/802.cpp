class Solution {
	// Idea is to use back-edge based dfs (discovered nodes and visited nodes concept)
	int dfs(int node, vector<int> &visited, vector<int> &ending, vector<vector<int>> &graph) {
		// if node has been fully discovered
		if (visited[node] == 2) 
			return ending[node];
		// if node has been visited but not fully discovered (a directed cycle)
		else if (visited[node] == 1) 
			return ending[node] = 1;
		visited[node] += 1;

		for (auto child: graph[node]) 
			ending[node] = (dfs(child, visited, ending, graph) == 1? 1: ending[node]);

		visited[node] += 1;
		// update ending if required (if each outgoing edge led to end)
		ending[node] = (ending[node] == 0 ? 2: ending[node]);
		return ending[node];
	}

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0), ending(n, 0), answer;
        
        for (int i = 0; i < n; i += 1) 
        	dfs(i, visited, ending, graph);

        // filter the ones which go to end
        for (int i = 0; i < n; i += 1) {
        	if (ending[i] == 2)
        		answer.push_back(i);
        }

        return answer;
    }
};