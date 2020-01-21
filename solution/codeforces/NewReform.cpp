// https://codeforces.com/problemset/problem/659/E

// read editorial for explaination

#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
const int N =1e5+5;

vector<int> graph[N],vis(N,0);
int n,m,edge,vertex,ans=0;

// does dfs to find num of edge,vertex in current connected component
void dfs(int node,int par=0){
    vis[node] = 1;
    vertex += 1;
    for(auto nei:graph[node]){
        if(nei==par)
            continue;
        else if(vis[nei])
            edge += 1;
        else {
            dfs(nei,node);
            edge +=1 ;
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;    cin >> u >> v;
        graph[u].push_back(v);  
        graph[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(vis[i])
            continue;
        edge=0,vertex=0;
        dfs(i);
        ans += (vertex==edge+1);
    }

    cout << ans << '\n';

    return 0;
}