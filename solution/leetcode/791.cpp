// https://leetcode.com/problems/custom-sort-string/
// Simple Topological Sort Based solution

class Solution {
public:
    vector<int> graph[26];
    vector<int> indegree;
    int n;  string ans;
    
    void dfs(int node, int par) {
        indegree[node] = -1;
        ans += ('a'+node);
        for (auto child: graph[node]) {
            if (child == par)
                continue;
            
            indegree[child] -= 1;
            if (indegree[child] == 0)
                dfs(child, node);
        }
    }
        
    string customSortString(string s, string T) {
        n = s.size();   indegree.resize(26);
        fill(indegree.begin(), indegree.end(), 0);
        
        // build graph
        for (int i = 0; i < n; i += 1) {
            for (int j = i+1; j < n; j += 1) {
                graph[s[i]-'a'].push_back(s[j]-'a');
                indegree[s[j]-'a'] += 1;
            }
        }
        
        // do Topological Sort
        for (int i = 0; i < 26; i += 1) {
            if (indegree[i] == 0)
                dfs(i, -1);
        }
        
        string solution;    map<char, int> freq;
        for (auto it: T)
            freq[it] += 1;
        
        // find answer based on Topological Sort
        for (auto ch: ans) {
            while(freq[ch]--)
                solution += ch;
        }
        
        return solution;
    }
};