// https://practice.geeksforgeeks.org/problems/reach-a-given-score/0
// Similar to 0-1 knapsack
// Time: O(n), Space: O(n), can be reduced to O(10)
// Iterative DP ^_^

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()
#define IOS ios_base::sync_with_stdio(false);    cin.tie(0);    cout.tie(0);
 
const int inf = 0x3f3f3f3f;
const ll INF = 0xFFFFFFFFFFFFFFFL;
 
typedef tree<int,null_type, /*greater<int>,*/
less<int>,rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
// find_by_order() and order_of_key() returns pointers
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
 
 
int n;
vector<vector<int>> dp;
vector<int> cost = {3, 5, 10};

void solve(){
    cin >> n;
    dp = vector<vector<int>> (3, vector<int>(n+1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i += 1) {
        // dp[0][i]: current cost is cost[0]
        for (int j = 0; j < cost.size(); j += 1) {
            if (i >= cost[j])
                dp[j][i] = dp[0][i-cost[j]] + dp[1][i-cost[j]]*(j >= 1) + dp[2][i-cost[j]]*(j >= 2);
        }
    }

    cout << dp[0][n] + dp[1][n] + dp[2][n] << '\n';
}

 
int main(){
    IOS;
    int test = 1;
    cin >> test; 
    while(test--)
        solve();
    return 0;
}
 
