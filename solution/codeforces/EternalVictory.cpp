// https://codeforces.com/contest/61/problem/D
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
vector<vector<pi> > graph;
vector<int> weight;
ll n,wt=0;

void dfs(int node,int par=0){
    for(auto it:graph[node]){
        if(it.first==par)
            continue;
        wt += it.second;
        dfs(it.first, node);
        wt += it.second;
        weight[node] = max(weight[node], weight[it.first] + it.second);
    }
}

int main(){
    cin >> n;
    graph.resize(n+1);
    weight.resize(n+1,0);
    for(int i=0;i+1<n;i++){
        int x,y,w;
        cin >> x >> y >> w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w));
    }

    dfs(1);
    cout << wt - weight[1] << '\n';

    return 0;
}