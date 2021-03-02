// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0), ans;
        for (auto e: edges)
            indegree[e[1]] += 1;
        for (int i = 0; i < n; i += 1) 
            if (indegree[i] == 0)
                ans.push_back(i);
        return ans;
    }
};