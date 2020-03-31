// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/xor-sum-1-af648068/
// squashed too much to fit the time limit


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll md=1e9+7,n,op;
vector<ll> a(100002,0);
vector<vector<ll> >v(400004,vector<ll> (ceil(log2(1e12)),0));

void fast_scanf(ll & number){
    auto ch = getchar_unlocked();
    number= 0;
    while (ch >= '0' && ch <= '9'){
        number = number * 10 + ch - '0';
        ch = getchar_unlocked();
    }
}

void build(int node,int left,int right){//building the segment tree
	if(left==right){//if leaf node is reached
		for(ll i=0;i<=ceil(log2(a[left]));i++)//for every bit check if it is set
			v[node][i]=(a[left] & (1LL)<<i)>0?1:0;
		return;
	}
	int mid=(left+right)/2;//else build the childs
	build(node*2,left,mid);
	build(node*2+1,mid+1,right);
	for(ll i=0;i<v[node].size();i++)//for every bit, store the results of its children
		v[node][i]=v[node*2][i]+v[node*2+1][i];	
}

vector<ll> give_query(int node,int left,int right,int ql,int qr){
	//gives vector whose 'i'the position gives number of elements in range left,right 
	//inclusive whose 'i'th bit is set
	if(ql>qr)
		return vector<ll> (ceil(log2(1e12)),0);
	else if(ql==left && qr==right)
		return v[node];
	
	int mid=(left+right)/2;
	vector<ll> vv=give_query(node*2,left,mid,ql,min(mid,qr));
	vector<ll> vv_=give_query(node*2+1,mid+1,right,max(mid+1,ql),qr);
	
	for(ll i=0;i<vv.size();i++)
		vv[i]+=vv_[i];
	return vv;
}

ll query(int left,int right){//a wrapper function 
	vector<ll> vv=give_query(1,1,n,left,right);
	//a vector whose index sores number of integers with that bit set
	ll ans=0;
	for(ll i=0;i<=op;i++){
		ll vill=(right-left+1-vv[i])*(right-left+1-vv[i]-1)/2;
		//no of ways of choosing 1 element out of vv[i] elements
		if(vv[i]>=3)//chose either 1 or 3 elements
			ans+= (vill*vv[i]+ (vv[i]*(vv[i]-1)*(vv[i]-2))/6)*(1LL<<i);
		else ans+=(vill*vv[i])*(1LL<<i);//choose 1 element

		ans%=md;
	}

	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    ll i,j,k,m,var;
    fast_scanf(n);
    for(i=1;i<=n;i++)
        fast_scanf(a[i]);
    build(1,1,n);
    op=ceil(log2(*max_element(a.begin(), a.end())))+1;
    fast_scanf(m); fast_scanf(var);

    while(m--){
        ll l,r;
        fast_scanf(l);	fast_scanf(r);
        cout<<query(l,r)<<"\n";
    }
    return 0;
}