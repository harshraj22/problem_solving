// Debug : debug template
// Number : number theory 

// ^_^ my first SOS Dp solution without any external help
// https://codeforces.com/contest/383/problem/E

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

int maxBit = 24;
int maxNum = (1<<maxBit);

// take string and convert it into integer, set 'i'th bit if 'i'th alphabet
// is present in string, eg 'a' converts to 1, while ab to 3
int convert(string s){
	int ans=0;
	for(char ch:s){
		// if 'i'th bit is already set, let it set, else set it
		ans = (ans | (1<<(ch-'a')));
	}
	return ans;
}

void solve(){
	// your main solution for each testcase
	ll n;	cin >> n;
	
	// dp[i] stores count of given words, such that (i & word)=i, here word = convert(word)
	// i.e. all the set bits of word are set in 'i', 'i' may have some extra set bits
	vector<ll> dp(maxNum,0);

	for(ll i=0;i<n;i++){
		string s;
		cin >> s;
		// (word & word) = word, so increase count by 1
		dp[convert(s)] += 1;
	}

	// standard SOS Dp implementation
	for(ll bit=0;bit<=maxBit;bit++){
		for(ll num=0;num<=maxNum;num++){
			// if 'bit'th bit is set
			if(num & (1<<bit))
				// add contribution from numbers whose 'bit'th bit is not set
				dp[num] += dp[num ^ (1<<bit)];
		}
	}

	ll ans = 0;
	for(ll i=0;i<=maxNum;i++){
		// at least one vowel = (number of words) - (number of words with all consonents)
		// all consonents are those words, whose bits are set only if that bit is 0 in group represented
		// by the given set of vowels. eg. if (a,b) are vowels, 000000...0011 is set represented by this 
		// group. all consonents are words who have 1 only on places where (a,b) have 0, they may have
		// 0 where (a,b) have 0, but they must have 0 where (a,b) have 1
		ll all_consonent = dp[(~i) & ((1<<maxBit)-1)];
		ans ^= (n - all_consonent)*(n - all_consonent);
	}

	cout << ans << '\n';
}

int main(){
	IOS;
	int test=1;
	// cin >> test;
	while(test--)
		solve();

	return 0;
}
