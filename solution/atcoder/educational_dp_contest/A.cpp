#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e5+5;
ll dp[N]={-1},v[N],n;
const int inf=0x3f3f3f3f;
ll check(int index);


int main(){
memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<check(0)<<"\n";

    return 0;
}

ll check(int index){
    if(dp[index]!=-1)return dp[index];

    if(index==n-1)return dp[index]=0;
    else if(index==n-2)return dp[index]=abs(v[index]-v[index+1]);

    return dp[index]=min(abs(v[index]-v[index+1])+check(index+1),
                abs(v[index]-v[index+2])+check(index+2));
}