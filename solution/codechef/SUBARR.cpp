#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define eb emplace_back
#define pi pair<ll,ll>
#define mp make_pair
const ll INF = 0xFFFFFFFFFFFFFFFL;

typedef tree<pi,null_type,less<pi>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;

const int N=1e3+5;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	ll i,j,k,n,m=1,sol=0;
	ordered_set st;
	cin>>n>>k;	vector<ll> v(n),pr(n);
	for(i=0;i<n;i++){
		cin>>v[i];	v[i]-=k;
		if(i)pr[i]=pr[i-1]+v[i];
		else pr[i]=v[i];
		sol+=st.order_of_key(mp(pr[i],INF))+(pr[i]>=0);
		st.insert(mp(pr[i],m++));
	}
	cout<<sol<<"\n";
	return 0;
}