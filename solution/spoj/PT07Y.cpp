#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> v[(int)1e4+3];
#define eb emplace_back
bool tree=true,vis[(int)1e4+3];
void search(int node,int par);

int main(){
    ll n,m,i,j,k;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>j>>k;
        v[j].eb(k); v[k].eb(j);
    }
    search(j,-1);
    if(m==n-1 && tree)cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

void search(int node,int par){
    if(vis[node]){
        tree=false;
        return ;
    }
    vis[node]=true;
    for(auto it:v[node]){
        if(it==par)continue;
        search(it,node);
    }
}