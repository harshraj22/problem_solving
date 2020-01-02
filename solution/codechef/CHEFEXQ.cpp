// Debug : debug template
// Number : number theory 

// Sqrt Decomposition Based Solution
// https://www.codechef.com/problems/CHEFEXQ

/*
	Idea: Break the input array into blocks of size sqrt(n). For each block,
		calculate prefix xor(Xor[i] = Xor[l]^Xor[l+1]...Xor[i-1]^Xor[i], where l is the
		leftmost index of current block). Also calculate xor of all elements of each block
		and store it. While query, we need number of positions such that prefix xor is
		the given value (say 'val'). Count number of prefix xors in first block which are 
		equal to 'val'. For second block, we need to count val^(xor of all elements first block)
		and so on. For each block, sort the prefix xors to make search fast. For update, 
		recalculate the total xor of block and prefix xor of the corresponding block. 
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

int n,q,blockSize;
// Xor contains xor of each element of blocks
// v contains prefix xor (explained in 'caclXor' function) of each blocks in 
// sorted order for each block
vector<int> a,v,Xor;

void calcXor(int from, int to, int & in){
	// given a range, it stores the xor of all elements in that range in 
	// the appropriate block
	// also it calculates the prefix xor, it v[l] = v[l], v[l+1] = v[l]^v[l+1]... where
	// l is the left most index of current block
	int cur=0,initial=0;
	while(from<to){
		cur ^= a[from];
		initial ^= a[from];
		v[from] = initial;

		from += 1;
	}
	in = cur;

}

void init(){
	// initialise all arrays
	v = a;
	blockSize = sqrt(n);
	Xor.resize(n/blockSize+2,0);
	int left=0;
	while(left+blockSize<=n){
		// for each block, update prefix xors and store the xor of all elements 
		calcXor(left, left+blockSize, Xor[left/blockSize]);
		// sort the prefix xor for each block for easy binary search
		sort(v.begin()+left, v.begin()+left+blockSize);
		left += blockSize;
	}
	if(left<n){
		// for last block whose size might not be sqrt(n)
		calcXor(left, n, Xor[left/blockSize]);
		sort(v.begin()+left, v.end());
	}
}

void update(int index, int val){
	// updates the value at position 'index' to 'val'
	// oldVal is value of array at 'index', left is the left most position
	// of the block to which 'index' belongs
	int oldVal=a[index], sortedIndex, left=blockSize*(index/blockSize);
	// sortedIndex = lower_bound(v.begin()+left, v.begin()+min(n, left+blockSize), oldVal) - v.begin();
	// update the value of array at given position
	a[index] = val;
	// v[sortedIndex] = val;
	// update the block of sorted xor to which 'index' belongs
	calcXor(left, min(n,left+blockSize), Xor[index/blockSize]);
	sort(v.begin()+left, v.begin()+min(n, left+blockSize));
}

ll query(int index, int val){
	// returns number of indexes, such that xors of a[i] for all i form 0 to index is 'val'
	int left=0,curXor=val,ans=0;
	// curXor contains the xor needed from current block/position
	while(left+blockSize<=index){
		// for each block, count number of indexes with prefix xor as curXor
		ans += upper_bound(v.begin()+left, v.begin()+min(n,left+blockSize), curXor) - lower_bound(v.begin()+left, v.begin()+min(n,left+blockSize), curXor);
		// update the value of curXor, as next block contains prefix xors with elements
		// starting from 'left+blockSize' and not '0'
		curXor ^= Xor[left/blockSize];
		left += blockSize;
	}
	while(left<=index){
		// for positions falling in last block, use array 'a' instead of v as v 
		// contains prefix xors in sorted order.
		ans += (a[left] == curXor);
		curXor ^= a[left];
		left += 1;
	}
	return ans;
}

void solve(){
	// your main solution for each testcase
	cin >> n >> q;
	a.resize(n);

	for(auto &it:a)
		cin >> it;
	init();

	while(q--){
		int type, index, val;
		cin >> type >> index >> val;
		if(type==1){
			update(index-1, val);
		}
		else{
			cout << query(index-1, val) << "\n";
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
