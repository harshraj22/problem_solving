// https://www.codechef.com/problems/RRATING
// https://www.codechef.com/status/RRATING,harshraj22
// Think why one of them gives TLE ^_^

// Think how it can be solved using segment trees @_@. Obiously segment tree for this problem is an overkill.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pi pair<int,int>

typedef tree<pi,null_type,
greater<pi>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	int numOfOperations, counter=0;
	cin >> numOfOperations;
	ordered_set st;
	while(numOfOperations--){
		int type,rating;
		cin >> type;
		if(type==1){
			cin >> rating;
			counter += 1;
			st.insert(make_pair(rating, counter));
		}
		else{
			if(st.size()<3){
				cout << "No reviews yet\n";
			}
			else{
				int last=(int)st.size()/3;
				cout << st.find_by_order(last-1)->first << "\n";
			}
		}
	}
	return 0;
}
