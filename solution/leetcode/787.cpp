// https://leetcode.com/problems/cheapest-flights-within-k-stops/
// DP on graphs

class Solution {
    int dp[101][101][101], inf;
    vector<vector<pair<int, int>>> graph;

    int minPrice(int src, int dst, int stops) {
        if (stops < 0) return inf;
        else if (src == dst) return 0;
        else if (dp[src][dst][stops] != -1)
            return dp[src][dst][stops];
        // mark as inf, to be safe from cycle
        dp[src][dst][stops] = inf;
        for (auto neighbour: graph[src]) {
            int v = neighbour.first, wt = neighbour.second;
            int cost = min(inf, wt + minPrice(v, dst, stops-1));
            dp[src][dst][stops] = min(dp[src][dst][stops], cost);
        }

        return dp[src][dst][stops];
    }

public:
    Solution() {
        for (int i = 0; i < 101; i += 1) {
            for (int j = 0; j < 101; j += 1) {
                for (int k = 0; k < 101; k += 1)
                    dp[i][j][k] = -1;
            }
        }
        graph.clear();
        inf = 1e7;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        graph = vector<vector<pair<int, int>>> (n+1);
        for (auto flight: flights) {
            int u = flight[0], v = flight[1], wt = flight[2];
            graph[u].push_back({v, wt});
            // graph[v].push_back({u, wt});
        }

        return minPrice(src, dst, K+1) < inf ? minPrice(src, dst, K+1): -1;
    }
};