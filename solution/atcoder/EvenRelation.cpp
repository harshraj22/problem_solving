// https://atcoder.jp/contests/abc126/tasks/abc126_d
// odd length => diff col, even length => same col

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
const int N=1e5+5;

vector<vector<pi> > graph;
vector<int> colour,visited;
int n;

void dfs(int node,int par=0,int col=1){
    visited[node] = 1;
    colour[node] = col;
    for(auto it:graph[node]){
        if(it.first==par)
            continue;
        else if(it.second%2==1)
            dfs(it.first,node,1-col);
        else 
            dfs(it.first,node,col);
    }
}

int main(){
    cin >> n;
    graph.resize(n+1);
    colour.resize(n+1);
    visited.resize(n+1,0);
    fill(visited.begin(),visited.end(),0);
    for(int i=1;i<n;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    for(int i=1;i<=n;i++){
        if(visited[i]==0)
            dfs(i);
    }

    for(int i=1;i<=n;i++)
        cout << colour[i] << '\n';

    return 0;
}