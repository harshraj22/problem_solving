#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 0xFFFFFFFFFFFFFFFL;

ll dp[402][402]={-1},n,ar[402],pr[402];

ll solve(int i,int j){
    if(dp[i][j]!=-1)
        return dp[i][j];
    else if(i==j)
        return dp[i][j]=0;
    ll var = INF;
    for(int k=i;k<j;k++){
        var=min(var,solve(i,k)+solve(k+1,j)+pr[j]-pr[i-1]);
    }
    return dp[i][j]=var;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ar[i];
    for(int i=0;i<=n;i++)
        pr[i]=pr[i-1]+ar[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,n)<<"\n";

    return 0;
}