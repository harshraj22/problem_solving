// similar to codechef PRMQ
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int

typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,
tree_order_statistics_node_update>ordered_set;

const int N = 3e4+3;
ll n,q,a[N],ans=0,var=0;
ordered_set seg[4*N];

void build(int node,int l,int r){
	if(l==r){
		seg[node].insert({a[l],var++});
		return;
	}
	int mid = l+(r-l)/2;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	for(auto it:seg[node*2])seg[node].insert(it);
	for(auto it:seg[node*2+1])seg[node].insert(it);
}

int query(int node,int l,int r,int ql,int qr,int val){
	if(ql>r || qr<l)return 0;
	else if(ql<=l && qr>=r)return (int)seg[node].size()
					-seg[node].order_of_key({val,var});
	int mid=l+(r-l)/2;
	return query(node*2,l,mid,ql,qr,val)+
			query(node*2+1,mid+1,r,ql,qr,val);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	cin>>q;
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		a ^= ans;	a = (a<1?1:a);
		b ^= ans;	b = (b>n?n:b);
		c ^= ans;	
		if(a <= b)
			ans = query(1,1,n,a,b,c);
		else ans = 0;
		cout<<ans<<"\n";
	}
	return 0;
}