// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
    void dfs(int node, bool curCol, vector<vector<int>> &graph, vector<int> &color, bool &bipertite) {
    	// if current node was already assigned some different color
    	// the graph can not be bipertite
        if (color[node] != -1) {
            bipertite = (color[node] == curCol ? bipertite: false);
            return;
        }
        color[node] = curCol;
        for (auto child: graph[node]) 
            dfs(child, 1-curCol, graph, color, bipertite);
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool bipertite = true;
        int n = graph.size();
        vector<int> color(n+1, -1);

        // for each uncoloured node, do dfs to find
        // if component represented by it is bipertite or not
        for (int i = 0; i < n; i += 1) {
            if (color[i] == -1)
                dfs(i, 0, graph, color, bipertite);
        }
        
        return bipertite;
    }
};