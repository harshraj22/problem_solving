// https://codeforces.com/contest/151/problem/D
// https://codeforces.com/blog/entry/3905?#comment-513516
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9+7;

int n,m,k,component=0;
vector<vector<int> > graph;
vector<bool> visited;

void dfs(int node,int par=0){
    visited[node] = 1;
    for(auto it:graph[node]){
        if(it==par)
            continue;
        else if(visited[it])
            continue;
        dfs(it,node);
    }
}

ll power(ll x, ll y){
    ll res = 1;
    while(y > 0){
        if(y%2==1)
            res = (res*x)%mod;

        y /= 2;
        x = (x*x)%mod;
    }
    return res;
}

int main(){
    cin >> n >> m >> k;
    graph.resize(n+1);
    visited.resize(n+1,false);

    for(int i=1;i<=n;i++){
        if(i+k-1>n)
            break;
        graph[i+k-1].push_back(i);
        graph[i].push_back(i+k-1);
        int low = i,high = i+k-1;
        while(low <=  high){
            graph[low].push_back(high);
            graph[high].push_back(low);
            low += 1;
            high -= 1;
        }
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            component += 1;
            dfs(i);
        }
    }

    cout << power(m,component) << '\n';

    return 0;
}