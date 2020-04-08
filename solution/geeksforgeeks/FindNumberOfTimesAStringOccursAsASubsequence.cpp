// https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence/0

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1001;
int n, m;
int dp[N][N];
string s1, s2;
    
void init() {
    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < N; j += 1) 
            dp[i][j] = -1;
    }
}

int recur(int n, int m) {
    if (m==-1)
        return 1;
    else if (n < 0 || m < -1)
        return 0;
    else if (dp[n][m] != -1)
        return dp[n][m];
        
    dp[n][m] = recur(n-1, m);    
    
    if (s1[n] == s2[m])
        dp[n][m] += recur(n-1, m-1);
        
    return dp[n][m];
}

void solve() {
    init();
    cin >> n >> m;

    cin >> s1 >> s2;
    // find s2 in s1
    cout << recur(n-1, m-1) << '\n';
}

int main(){
	int test = 1;
	cin >> test;
	while(test--)
	    solve();
	
	return 0;
}