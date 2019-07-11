#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N=1e3+2;
const ll md=1e9+7;
ll dp[N][N],n,m,ar[N][N];

int main(){
ll i,j,k;   char ch;
memset(dp,0,sizeof(dp));
cin>>n>>m;
for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        cin>>ch;
        if(ch=='#')
            dp[i][j]=-1;
    }
}
dp[1][1]=1;
for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        if(!(i==1 && j==1) && dp[i][j]!=-1)
            dp[i][j]=(dp[i-1][j]*(dp[i-1][j]!=-1)+dp[i][j-1]*(dp[i][j-1]!=-1))%md;
    }
}
cout<<dp[n][m]<<"\n";
    return 0;
}