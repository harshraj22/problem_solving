// Debug : debug template
// Number : number theory 

// Idea taken from codeforces : https://codeforces.com/blog/entry/45223

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

const int maxBits = 21;
const int maxNum = (1<<maxBits);

/*
	a[i] & a[j] == 0 is same as (a[i] | (~a[j])) = a[i], where a[i] >= a[j]
	remember a[i] is also less than (1<<maxBits), so we calculate sum over subsets
	(as explained in codeforces blog) and for final answer, we calculate these sums
	over ~a[i].

*/

void solve(){
	// your main solution for each testcase

	int n;
	cin >> n;
	vector<int> a(n), dp(maxNum,0);

	// dp[i] stores number of j such that (a[i] | a[j]) = a[i]
	for(int i=0;i<n;i++){
		cin >> a[i];
		// for all a[i], (a[i] | a[i]) = a[i]
		dp[a[i]] += 1;
	}

	for(int bit=0;bit<=maxBits;bit++){
		for(int num=0;num<maxNum;num++){
			// if 'i'th bit of current number is set
			if(num & (1<<bit))
				// add contribution due to number whose 'i'th bit is not set and all other bits are same
				dp[num] += dp[num^(1<<bit)];
		}
	}

	ll ans=0;

	for(int i=0;i<n;i++){
		// finally count the answer, Remember ~a[i] also inverts the bit that corresponds to sign
		// and other higher bits that we are not interested in.

		// (1<<maxBits) sets the 'maxBits'th bit
		// (1<<maxBits)-1 swaps all bits from rightmost set bit to rightmost bit
		// so taking &, results in inverting only bits from rightmost bit to 'maxBits' in a[i]
		ans += dp[(~a[i]) & ((1<<maxBits)-1)];
	}

	cout << ans << '\n';
}

int main(){
	IOS;
	int test=1;
	cin >> test;
	while(test--)
		solve();

	return 0;
}
