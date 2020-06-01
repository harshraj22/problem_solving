// https://practice.geeksforgeeks.org/problems/cutted-segments/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

int n;
vector<int> len(3), dp;

int recur(int num) {
    if (num == 0)
        return 0;
    else if (num < 0)
        return -1e5;
    else if (dp[num] != -1)
        return dp[num];
    dp[num] = -1e5;
    for (int i = 0; i < len.size(); i += 1) {
        dp[num] = max(dp[num], 1 + recur(num-len[i]));
    }
    
    return dp[num];
}

void solve(){
    cin >> n >> len[0] >> len[1] >> len[2];
    dp = vector<int> (n+1, -1);
    cout << recur(n) << '\n'; 
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