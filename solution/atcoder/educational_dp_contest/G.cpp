#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N=1e5+3;
vector<int> v[N];
ll ans=0,n,dp[N];
#define eb emplace_back
ll dfs(int node,int par);

int main(){
ll i,j,k,m;
cin>>n>>m;
memset(dp,-1,sizeof(dp));
while(m--){
    cin>>i>>j;
    v[i].eb(j);
}
for(i=1;i<=n;i++){
    if(dp[i]==-1)
        dfs(i,-1);
} 
cout<<ans<<"\n";
    return 0;
}

ll dfs(int node,int par){
    if(dp[node]!=-1)
        return dp[node];
    else if(v[node].empty())
        return dp[node]=0;
    for(auto it:v[node]){
        if(it==par)continue;
        dp[node]=max(dp[node],dfs(it,node)+1);
    }
    ans=max(ans,dp[node]);
    return dp[node];
}