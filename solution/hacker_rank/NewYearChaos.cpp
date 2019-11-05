// https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int 

typedef tree< int,null_type,
less<int>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

/*
	Traverse the given array in reverse direction,
	and see if there is any element which has swapped more than
	twice. Use policy based data structure for faster lookups.
*/

void solve(){
	int numOfPeople, ans = 0;
	cin >> numOfPeople;
	vector<int> people(numOfPeople);
	bool possible = true;
	ordered_set st;

	for(int i=0;i<people.size();i++)
		cin >> people[i];

	for(int i=(int)people.size()-1;i>=0;i--){
		if(st.order_of_key(people[i]) > 2){
			possible = false;
		}
		else{
			ans += st.order_of_key(people[i]);
			st.insert(people[i]);
		}
	}
	if(possible)	
		cout << ans << '\n';
	else
		cout << "Too chaotic\n";

}

int main(){

	int test;
	cin >> test;
	while(test--)
		solve();

	return 0;
}