// https://leetcode.com/problems/course-schedule/
// Simple `Topological Sort` based solution
// 		if a directed cycle exists, the nodes of cycle will never be visited

class Solution {
    int n;
    bool ans = true;
    vector<bool> vis;
    vector<int> indegree;
    vector<vector<int>> graph;
    
    void dfs(int node) {
        if (vis[node]){
            ans = false;
            return;
        } 
        vis[node] = true;
        
        for (auto child: graph[node]) {
            indegree[child] -= 1;
            if (indegree[child] == 0)
                dfs(child);
        }
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        indegree.resize(n); vis.resize(n);
        graph.resize(n);
        fill(vis.begin(), vis.end(), false);
        fill(indegree.begin(), indegree.end(), 0);
        
        for (auto it: prerequisites) {
            int u = it[0], v = it[1];
            graph[u].push_back(v);
            indegree[v] += 1;
        }
        
        for (int i = 0; i < n; i += 1) {
            if (indegree[i] == 0 && vis[i] == false) {
                dfs(i);
                indegree[i] -= 1;
            }
        }
        
        if (accumulate(vis.begin(), vis.end(), 0) != n)
            ans = false;
        
        return ans;
    }
};


/*

class Solution:
    from collections import defaultdict
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        incoming = [0 for _ in range(numCourses)]
        graph = defaultdict(list)
        start = []
        
        for (u, v) in prerequisites:
            graph[u].append(v)
            incoming[v] += 1
            
        for index, val in enumerate(incoming):
            if val == 0:
                start.append(index)
                
        while start:
            node = start.pop()
            for child in graph[node]:
                incoming[child] -= 1
                if incoming[child] == 0:
                    start.append(child)
                elif incoming[child] < 0:
                    return False
        
        return all(x == 0 for x in incoming)
        

*/
