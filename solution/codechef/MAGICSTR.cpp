// idea from editorial : http://discuss.codechef.com/problems/MAGICSTR

// Debug : debug template
// Number : number theory 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define pi pair<int,int>
#define IOS ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);

const int inf = 0x3f3f3f3f;
const ll INF = 0xFFFFFFFFFFFFFFFL;

typedef tree<int,null_type, /*greater<int>,*/
less<int>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// find_by_order() and order_of_key() returns pointers
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)


ll modpow(ll a,ll b,ll MOD) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;} 
// (a^b)%MOD

const int N=2e3+4, mod=1e9+7;
int n,m;

vector<int> par, weight;

int find_par(int x){
	if(x==par[x])
		return x;
	return par[x] = find_par(par[x]);
}

void join(int x, int y){
	int px=find_par(x), py=find_par(y);
	if(px==py)
		return;
	else if(weight[px]>weight[py]){
		par[py] = px;
		weight[px] += weight[py];
	}
	else{
		par[px] = py;
		weight[py] += weight[px];
	}
}

void solve(){
	// your main solution for each testcase
	cin >> n >> m;
	par.resize(n);	weight.resize(n,1);
	iota(par.begin(), par.end(), 0);

	// (7,2) and (6,2) will round off to give same midpoint. So making 2 midpoint vectors.
	vector<pi> queries_even(n, make_pair(-1,-1)),  queries_odd(n, make_pair(-1,-1));

	while(m--){
		int l,r,prel,prer;
		cin >> l >> r;
		l -= 1; r -= 1;
		ll mid=(l+r)/2;
		if((l+r)%2==0){
			// even
			prel=queries_even[mid].first, prer=queries_even[mid].second;
			if(prer-prel <= r-l)
				queries_even[mid] = make_pair(l,r);
		}
		else{
			// odd
			prel=queries_odd[mid].first, prer=queries_odd[mid].second;
			if(prer-prel <= r-l)
				queries_odd[mid] = make_pair(l,r);
		}

	}

	for(auto it:queries_even){
		if(it.first >= 0){
			int l=it.first, r=it.second;
			while(l<=r){
				join(l, r);
				l+=1; r-=1;
			}
		}
	}


	for(auto it:queries_odd){
		if(it.first >= 0){
			int l=it.first, r=it.second;
			while(l<=r){
				join(l, r);
				l+=1; r-=1;
			}
		}
	}

	int heads=0;
	for(int i=0;i<n;i++)
		if(i==par[i])
			heads += 1;
	cout << modpow(26, heads, mod) << "\n";

}

int main(){
	IOS;
	int test=1;
	cin >> test;
	while(test--)
		solve();

	return 0;
}
