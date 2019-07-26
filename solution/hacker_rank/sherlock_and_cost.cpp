/*
 Good DP
 optimal solution must consist of either 1 or Bi for each position. proof left to reader. 
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define eb emplace_back
#define pi pair<ll,ll>
#define mp make_pair
const ll INF = -0x3f3f3f3f;

typedef tree<pi,null_type,less<pi>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;

ofstream fout(getenv("OUTPUT_PATH"));
#define cout fout

const int N=1e5+5;
vector<ll> a,b;
ll n,dp[2][N];

ll solve(int dig,int index){
	if(dp[dig][index]!=-1)return dp[dig][index];

	if(index==0){
		dp[0][index]=dp[1][index]=0;
		return dp[dig][index];
	}

	ll mn=INF,glo=INF;
	if(dig==1)
		dp[dig][index]=max(abs(b[index]-b[index-1])+solve(1,index-1),
			abs(b[index]-1)+solve(0,index-1));
	else
		dp[dig][index]=max(abs(1-b[index-1])+solve(1,index-1),
			abs(1-1)+solve(0,index-1));

	return dp[dig][index];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int test;	cin>>test;
	while(test--){
		ll m=INF;
		cin>>n;	
		memset(dp,-1,sizeof(dp));
		b.resize(n);
		for(int i=0;i<n;i++)cin>>b[i];
		m=max({m,solve(0,n-1),solve(1,n-1)});
		cout<<m<<"\n";
	} 
	return 0;
}