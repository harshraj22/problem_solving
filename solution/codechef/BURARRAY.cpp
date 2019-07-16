// my first persistent seg tree solution. Thanks to blake_786
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e7*7;
#define deb(x) cerr << #x << " = " << x << " ";

ll nod;
struct tree{
	ll left=0,right=0,count=0;	
} seg[N];

void put(ll &node,ll lrange,ll rrange,ll val){
	if(node==0)node=++nod;
	if(lrange==rrange){
		seg[node].count=1;
		// deb(node); cout<<"---\n";
		return;
	}
	ll mid=(lrange+rrange)/2;

	if(val<=mid)put(seg[node].left,lrange,mid,val);
	else put(seg[node].right,mid+1,rrange,val);

	ll lc=seg[node].left,rc=seg[node].right;	//left and right child
	if(seg[lc].count==mid-lrange+1)
		seg[node].count=seg[lc].count+seg[rc].count;
	else seg[node].count=seg[lc].count;
}

ll query(ll node,ll lrange,ll rrange,ll val){
	if(node==0){
		// deb(lrange);	deb(rrange);	deb(val);	deb(node);	cout<<endl;
		// return val;
		return min(val,rrange);
	}
	else if(lrange==rrange)return 0;
	ll mid=(lrange+rrange)/2;
	ll rc=seg[node].right,lc=seg[node].left;

	if(val>mid && min(rrange,val)-(mid+1)+1>seg[rc].count)
		return query(rc,mid+1,rrange,val);
	else return query(lc,lrange,mid,val);

}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int test;	cin>>test;
	while(test--){
		ll n,q;
		cin>>n>>q;
		ll s=0,i,j,k,m,t,root=0;
		while(q--){
			cin>>t;
			if(t==1){
				cin>>j;	j+=s;
				put(root,1,n,j);
			}
			else{
				ll l,r;	cin>>l>>r;
				ll res=query(root,1,n,r+s);
				if(res<l+s)
					cout<<"0\n";
				else{
					cout<<res<<"\n";
					s+=res;	s%=n;
				}
			}
		}
		for(ll i=0;i<=nod;i++)
			seg[i].left=seg[i].right=seg[i].count=0;
	}
	return 0;
}