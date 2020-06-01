// https://practice.geeksforgeeks.org/problems/coin-change/0
// The subset of coins matters

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

vector<vector<int>> dp;
vector<int> price;
int n, target;

// dp[num][index]: try to get change for 'num' using coins 
// from price[:index]
// if we try to recur using just num, 5 = {1,1,3} and {3,1,1} 
// might be counted differently
int recur(int num, int index) {
    if (num == 0)
        return 1;
    else if (num < 0)
        return 0;
    else if (index < 0)
        return 0;
    else if (dp[num][index] != -1)
        return dp[num][index];
    return dp[num][index] = recur(num, index-1) + recur(num-price[index], index);
}

void solve(){
    cin >> n;
    price.resize(n);
    for (auto &it: price) 
        cin >> it;
    cin >> target;
    dp = vector<vector<int>> (target+1, vector<int> (n+1, -1));
    cout << recur(target, n-1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    int test = 1;
    cin >> test;
    while(test--)
        solve();
    return 0;
}