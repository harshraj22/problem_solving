* An awesome problem
* Solved 1 min after the contest ended :(

```c++
// https://codeforces.com/contest/1328/problem/D
// coloring bipertite graph

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

vector<int> ans, type;

void print(vector<int> v) {
    cout << *max_element(v.begin(), v.end()) << '\n';
    for (auto it: v)
        cout << it << ' ';
    cout << '\n';
}

bool all_distinct() {
    // all pair of adjacent types are distinct 
    for (int i = 1; i < type.size(); i += 1) {
        if (type[i] == type[i-1])
            return false;
    }
    return type[0] != type.back();
}

vector<vector<int>> graph;
vector<int> vis;

void dfs(int node, int par, int col = 1) {
    if (vis[node] != 0)
        return;
    ans[node] = col; vis[node] = 1;
    for (auto child: graph[node]) {
        if (child != par) {
            dfs(child, node, 3 - col);
        }
    }
}

void solve(){
    int n;  cin >> n;
    type.resize(n); ans.resize(n, 0);
    vis.resize(n);  fill(vis.begin(), vis.end(), 0);
    for (auto &it: type) cin >> it;

    ans[0] = 1; 

    // all elements are same type
    if (count(type.begin(), type.end(), type[0]) == n) {
        fill(ans.begin(), ans.end(), 1);
        print(ans);
        return;
    }
    // all elements are not same and even num of ele
    else if (n % 2 == 0) {
        for (int i = 0; i < n; i += 1)
            ans[i] = 1 + i%2;
        print(ans);
        return;
    }
    // odd num of element and all pair of adjacent are distinct
    else if (all_distinct()) {
        for (int i = 0; i < n; i += 1)
            ans[i] = 1 + i%2;
        ans[0] = 3;
        print(ans); return;
    }

    // odd num of element and all pair of adjacent are not distinct
    graph.resize(n+1);
    for (auto &it: graph) it.clear();
    for (int i = 0; i+1 < n; i += 1) {
        if (type[i] != type[i+1]) {
            graph[i].push_back(i+1);
            graph[i+1].push_back(i);
        }
    }

    if (type[0] != type[n-1]) {
        graph[0].push_back(n-1);
        graph[n-1].push_back(0);
    }

    for (int i = 0; i < n; i += 1) {
        if (vis[i] == 0) {
            dfs(i, -1);
        }
    }

    print(vector<int> (ans.begin(), ans.begin()+n));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    int test = 1;
    cin >> test;
    while(test--)
        solve();
    return 0;
}
```