Problem: 
   - [Day 30](https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/553/week-5-august-29th-august-31st/3442/)

Tried: 
   - `DSU` with `Sieve`


```c++
// Time: O(NlogN), N = 10**5
// Idea: Form graph using sieve. Add edges using DSU

class Solution {
    int n, len, N;
    set<int> nodes;
    vector<int> parent, rank;

    int find_par(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find_par(parent[node]);
    }

    void merge(int u, int v) {
        if (u == v) 
            return;
        if (rank[u] < rank[v])
            swap(u, v);

        // now, rank[u] >= rank[v];
        parent[v] = u;
        rank[u] += rank[v];
        len = max(len, rank[u]);
    }

    void sieve() {
        vector<int> primes(N, false);

        for (int i = 2; i < primes.size(); i += 1) {
            if (primes[i] == true)
                continue;
            for (int j = i; j < primes.size(); j += i) {
                primes[j] = true;

                // add edge to create/ merge the trees
                // merge tree represented by i, and tree represented by j
                if (parent[j] == -1)
                    continue;
                else if (parent[i] == -1) {
                    parent[i] = parent[j];
                    continue;
                }

                int u = find_par(i), v = find_par(j);
                merge(u, v);
            }
        }
    }

public:
    int largestComponentSize(vector<int>& A) {
        n = A.size();
        len = 0;
        N = 1e5 + 3;
        nodes = set<int> (A.begin(), A.end());
        parent = vector<int> (N, -1);
        rank = vector<int> (N, 1);

        // iota(parent.begin(), parent.end(), 0);
        for (auto num: A)
            parent[num] = num;

        sieve();
        return len;
    }
};
```
