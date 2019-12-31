// Debug : debug template
// Number : number theory 

// idea taken form solutions
// see more sos dp : https://github.com/harshraj22/problem_solving/blob/master/solution/
// https://codeforces.com/contest/165/problem/E

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

const int maxBit = 22;
const int maxNum = (1<<maxBit);

void solve(){
	// your main solution for each testcase

	int n;
	cin >> n;
	vector<int> a(n), dp(maxNum, -1);
	for(int i=0;i<n;i++){
		cin >> a[i];
		dp[a[i]] = a[i];
	}

	for(int bit=0;bit<maxBit;bit++){
		for(int num=0;num<maxNum;num++){
			if(num & (1<<bit))
				dp[num] = max(dp[num], dp[num ^ (1<<bit)]);
		}
	}

	for(int i=0;i<n;i++){
		cout << dp[(~a[i]) & ((1<<maxBit)-1)] << " \n"[i==n-1];
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
