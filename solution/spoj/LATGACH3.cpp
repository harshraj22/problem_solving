#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
ios_base::sync_with_stdio(false);
ll dp[2][32];
memset(dp,0,sizeof(dp));
dp[0][0]=1,	dp[1][1]=1;
for(ll i=2;i<32;i++){
	dp[0][i]=dp[0][i-2]+dp[1][i-1]*2;
	dp[1][i]=dp[0][i-1]+dp[1][i-2];
}
ll n;
cin>>n;
while(n!=-1){
	cout<<dp[0][n]<<"\n";
	cin>>n;
}
	return 0;
}