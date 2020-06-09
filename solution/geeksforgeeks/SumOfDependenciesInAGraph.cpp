// https://practice.geeksforgeeks.org/problems/sum-of-dependencies-in-a-graph/0

#include<bits/stdc++.h>
using namespace std;

void solve() {
    int v, e;   cin >> v >> e;
    vector<int> outdegree(v+1, 0);
    for (int i = 0; i < e; i += 1) {
        int u, v;   cin >> u >> v;
        outdegree[u] += 1;
    }

    cout << accumulate(outdegree.begin(), outdegree.end(), 0) << '\n';
}

int main() {
    int test;   cin >> test;
    while (test--)
        solve();

    return 0;
}
