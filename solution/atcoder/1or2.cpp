// https://atcoder.jp/contests/abc126/tasks/abc126_e
// count number of connected components in bidirected graph

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=1e5+5;
#define pi pair<int,int>

vector<vector<pi> > graph;
vector<int> vis,col;
int n,m,diff=0;

void dfs(int node,int par=0){
    vis[node] = 1;
    for(auto it:graph[node]){
        if(it.first == par)
            continue;
        else if(vis[it.first]==0)
            dfs(it.first,node);
    }
}

int main(){
    cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1);
    fill(vis.begin(),vis.end(),0);
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y,z));
        graph[y].push_back(make_pair(x,z));
    }

    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            dfs(i);
            diff += 1;    
        }
    }
    cout << diff << '\n';

    return 0;
}