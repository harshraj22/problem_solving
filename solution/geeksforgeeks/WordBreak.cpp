// https://practice.geeksforgeeks.org/problems/word-break/0/?track=interview-dynamic%20programming&batchId=117
// A standard Dynamic Programming Problem

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

const int N = 1e3 + 4;
int dp[N][N];

int n;  string str;
unordered_set<string> dict;

void init() {
    dict.clear();
    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < N; j += 1) {
            dp[i][j] = -1;
        }
    }
}

bool possible(int left, int right) {
    // check if it is valid

    // if already calculated
    if (dp[left][right] != -1)
        return dp[left][right];
    else if (dict.find(str.substr(left, right-left+1)) != dict.end())
        return dp[left][right] = 1;
    
    for (int i = left; i < right; i += 1) {
        if (possible(left, i) && possible(i+1, right))
            return dp[left][right] = 1;
    }

    return dp[left][right] = 0;
}

void solve(){
    init();
    cin >> n; string s;
    for (int i = 0; i < n; i += 1) {
        cin >> s;
        dict.insert(s);
    }

    cin >> str; n = str.size();
    cout << possible(0, n-1) << '\n';
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