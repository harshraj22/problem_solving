// https://leetcode.com/problems/keys-and-rooms/

class Solution {
    void dfs(int node, vector<bool> &vis, vector<vector<int>>& rooms) {
        if (vis[node])
            return;
        vis[node] = true;
        for (auto child: rooms[node])
            dfs(child, vis, rooms);
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        
        dfs(0, vis, rooms);
        return all_of(vis.begin(), vis.end(), [](bool x) {return x;});
    }
};