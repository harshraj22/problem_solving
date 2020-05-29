Problem: 
   - [Day 29](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/)

Tried: 
   - Used `DFS`

```c++
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
```