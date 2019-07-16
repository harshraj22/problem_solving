#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e3+500;

ll dp[N][N],n,k;
int recur(int floor,int egg);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
int test;   cin>>test;
while(test--){
    memset(dp,-1,sizeof(dp));
    int i,j;    cin>>k>>n;
    cout<<recur(n,k)<<"\n";
}
    return 0;
}

int recur(int floor,int egg){
    if(dp[floor][egg]!=-1)
        return dp[floor][egg];
    else if(egg==1)
        return dp[floor][egg]=floor;
    else if(floor<2)
        return dp[floor][egg]=floor;
    ll var=INT_MAX,mn=INT_MAX;
    for(int i=1;i<=floor;i++){
        var=max(recur(i-1,egg-1),recur(floor-i,egg))+1;
        mn=min(mn,var);
    }
    return dp[floor][egg]=mn;
}