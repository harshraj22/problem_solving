// Debug : debug template
// Number : number theory 

// https://www.spoj.com/problems/GIVEAWAY/

/*
	Idea : This seems basic question that can also be solved using 
		Square Root Decomposition. We divide the array into blocks of 
		size sqrt(n). We sort each block separately. For each query, we 
		do a binary search to find the answer. So for each query we take
		sqrt(n)*log(sqrt(n)) time as we traverse maximum sqrt(n) blocks
		and in each block we find ans using binary search taking log(sqrt(n))
		time.
*/

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

const int N=5e5+5;
int blockSize = sqrt(N);
vector<ll> a,v;
// a : input array
// v : array on which we operate, whose each block is sorted
ll n,q;

void init(){
	v = a;	blockSize = sqrt(n);
	// sorts each block
	ll l=0;
	while(l+blockSize<n){
		sort(v.begin()+l, v.begin()+l+blockSize);
		l += blockSize;
	}
	if(l<n){
		sort(v.begin()+l, v.end());
	}
}

ll query(int x, int y, int z){
	// num of elements in [x,y] greater than or equal to z
	ll l=x,ans=0;
	while(l<=y){
		while(l%blockSize){
			// reaching closest block border to l
			// note that we are using array 'a' and not 'v' as this segment is sorted,
			// so some elements with index<x might have come to index>x in 'v' when this
			// block was sorted, hence we go linearly until we reach indexes where 
			// whole block is to be queried
			ans += (a[l]>=z);
			l += 1;
			if(l>y)
				break;
		}

		while(l+blockSize<=y){
			// we reached the leftmost index of the nearest block, travelling through the blocks
			ans += (v.begin()+l+blockSize) - lower_bound(v.begin()+l, v.begin()+l+blockSize, z);
			l += blockSize;
		}

		while(l<=y){
			// reaching the end of interval
			ans += (a[l]>=z);
			l += 1;
		}
	}
	return ans;
}

void update(int index, int val){
	// update the value of array 'a' at index 'index' to value 'val'
	ll oldVal=a[index], l=(index/blockSize)*blockSize;
	// 'l' is the leftmost index of block to which index 'index' belongs
	// find position of 'oldVal' in array 'v' ini current block
	int oldIndex = lower_bound(v.begin()+l, v.begin()+min(n,l+blockSize), oldVal)-v.begin();
	// update both array 'a' and 'v'. We need to update array 'a' as well as we use it in query
	v[oldIndex]=val;
	a[index]=val;
	// sort the updated block
	sort(v.begin()+l, v.begin()+min(n,l+blockSize));	
}

void solve(){
	// your main solution for each testcase
	cin >> n;
	a.resize(n);
	for(int i=0;i<n;i++)
		cin >> a[i];
	// sort each blocks separately
	init();
	cin >> q;
	for(int i=0;i<q;i++){
		int type;
		cin >> type;
		if(type==0){
			int x,y,z;
			cin >> x >> y >> z;
			cout << query(x-1,y-1,z) << "\n";
		}
		else{
			int x,y;
			cin >> x >> y;
			update(x-1,y);
		}
	}

}

int main(){
	IOS;
	int test=1;
	// cin >> test;
	while(test--)
		solve();

	return 0;
}
