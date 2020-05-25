// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

#define all(a) a.begin(), a.end()

const int N = 1e6 + 5;
vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
vector<vector<int>> dp(N);

vector<int> recur(int amt) {
    if (amt < 0)
        return vector<int> (10, N);
    else if (amt == 0)
        return dp[0] = vector<int> (10, 0);

    assert(amt > 0 && amt < N);
    if (dp[amt].size() == 10)
        return dp[amt];
    dp[amt] = vector<int> (10, N);
    for (int i = 0; i < 10; i += 1) {
        assert(i < coins.size());
        auto coin = coins[i];
        auto var = recur(amt-coin);
        if (accumulate(all(dp[amt]), 0) > 1 + accumulate(all(var), 0)) {
            dp[amt] = var;
            assert(dp[amt].size() == 10);
            dp[amt][i] += 1;
        }
    }

    return dp[amt];
}

void solve(){
    int amt;    cin >> amt;
    auto ans = recur(amt);
    // sort(all(ans));
    for (int i = 9; i >= 0; i -= 1) {
        while (ans[i]--)
            cout << coins[i] << ' ';
    }
    cout << '\n';
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