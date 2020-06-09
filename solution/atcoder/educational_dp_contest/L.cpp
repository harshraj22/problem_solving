#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

ll sum, n;
vector<ll> values;
vector<vector<ll>> dp;

ll recur(int left, int right) {
    // returns the max diff (the current player is more)
    if (left == right) return values[left];
    else if (dp[left][right] != -1) 
        return dp[left][right];
    return dp[left][right] = max(values[left]-recur(left+1, right), values[right]-recur(left, right-1));
}

int main() {
    cin >> n;
    values = vector<ll> (n);
    dp = vector<vector<ll>> (n, vector<ll>(n, -1));

    for (auto &value: values)
        cin >> value;

    sum = accumulate(all(values), 0LL);
    // Taro tries to maximize X − Y , while Jiro tries to minimize X − Y
    // Taro starts the game

    cout << recur(0, n-1) << '\n';

    return 0;
}
