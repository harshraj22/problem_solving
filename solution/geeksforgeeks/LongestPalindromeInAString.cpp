// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

vector<vector<int>> dp;
string s, ans;

int recur(int left, int right) {
    if (left > right) 
        return false;
    else if (dp[left][right] != -1)
        return dp[left][right];
    else if (left == right)
        return dp[left][right] = 1;
    else if (left + 1 == right) {
        dp[left][right] = (s[left] == s[right]);
        if (dp[left][right] && ans.size() < 2)
            ans = s.substr(left, 2);
        return dp[left][right];
    }

    // recuring first to [left, right-1] ensures that first longest
    // palindrome is selected in case of conflict
    recur(left, right-1); recur(left+1, right);
    if (s[left] != s[right] || !recur(left+1, right-1))
        return dp[left][right] = 0;
    dp[left][right] = 1; 
    if (ans.size() < right-left+1)
        ans = s.substr(left, right-left+1);
    return dp[left][right];
}

void solve(){
    cin >> s;
    int n = s.size();
    dp = vector<vector<int>> (n, vector<int> (n, -1));
    ans = s[0];
    recur(0, (int)s.size()-1);
    cout << ans << '\n';
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