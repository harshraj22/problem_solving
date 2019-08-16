#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

const int N=1e5+3;
int dp[N]={-1},n,k,ar[102];

int solve(int sum){
    // if sum is negative, the previous player looses (0 return )
    if(sum<0)return 1;
    else if(sum==0)return 0;
    // if the result is already calculated, reutrn it
    else if(dp[sum]!=-1)return dp[sum];
    int s=1;
    // check if there is atleast one case which chosen, the opponent looses
    for(int i=0;i<n;i++)
        s=min(s,solve(sum-ar[i]));
    // if opponent looses, current player wins
    return dp[sum]=(!s);
}

int main(){
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
        cin>>ar[i];
    ll sum=0;

    sum=solve(k);
    if(sum)
        cout<<"First\n";
    else cout<<"Second\n";
return 0;
}