// Debug : debug template
// Number : number theory 

// idea from editorial : https://www.codechef.com/problems/MAXOR

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

const int N=21;
const int maxN=1e6+2;

void solve(){
	// your main solution for each testcase
	int n;
	cin >> n;
	vector<int> a(n), frequency(maxN,0), dp(maxN,0);
	for(int i=0;i<n;i++){
		cin >> a[i];
		frequency[a[i]] += 1;
		dp[a[i]] += 1;
	}

	for(int i=0;i<=N;i++){
		for(int mask=0;mask<maxN;mask++){
			// if 'i'th bit is swapable, but we are only considered with
			// numbers who replace 1 with 0 as they have a|b=b
			if(mask & (1<<i)){
				dp[mask] += dp[mask ^ (1<<i)];
			}
		}
	}

	ll ans = 0;
	for(int i=0;i<n;i++){
		// number of integers that are like a[i] 
		ans += dp[a[i]] - frequency[a[i]]; 
	}

	for(int i=0;i<maxN;i++){
		// choose 2 integers from a[i]
		ans += (frequency[i]*(frequency[i]-1))/2;
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
