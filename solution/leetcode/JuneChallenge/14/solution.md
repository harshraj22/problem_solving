Problem: 
   - [Day 14](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3360/)

Tried: 
   - Good `Dynamic Programming`


```c++
class Solution {
    int dp[101][101][101];
    vector<vector<pair<int, int>>> graph;
    int inf;

    int cheapest(int src, int dest, int stop) {
        if (src == dest && stop >= 0) 
            return 0;
        else if (stop < 0)
            return inf;
        else if (dp[src][dest][stop] != -1)
            return dp[src][dest][stop];

        dp[src][dest][stop] = inf;
        for (auto edge: graph[src]) 
            dp[src][dest][stop] = min(dp[src][dest][stop], edge.second + cheapest(edge.first, dest, stop-1));

        return dp[src][dest][stop];
    }

public:
    Solution() {
        for (int i = 0; i < 101; i += 1) {
            for (int j = 0; j < 101; j += 1) {
                for (int k = 0; k < 101; k += 1)
                    dp[i][j][k] = -1;
            }
        }

        inf = 1e7;
        graph.clear();
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        graph.resize(n+1);
        for (auto edge: flights) {
            int u = edge[0], v = edge[1], wt = edge[2];
            graph[u].push_back({v, wt});
        }

        return cheapest(src, dst, K+1) < inf ? cheapest(src, dst, K+1) : -1;
    }
};
```