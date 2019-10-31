// https://www.codechef.com/problems/TSECJ05

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including 

using namespace __gnu_pbds; 
using namespace std; 
  
#define ll long long int

typedef tree<ll, null_type, greater<ll>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    ordered_set; 
  

void solve(){
	ll n, k;
	ordered_set st;
	cin >> k >> n;
	for(int i=0;i<n;i++){
		ll var;
		cin >> var;
		st.insert(var);
		if(st.size() < k)
			cout << "-1 ";
		else
			cout << *st.find_by_order(k-1) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test;
	cin >> test;
	while(test--)
		solve();

	return 0;
}