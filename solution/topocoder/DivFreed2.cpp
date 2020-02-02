#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class DivFreed2{
    public:
        const int mod = 1e9+7;
        int count(int n, int k){
            // long long int dp[n+2][k+2];
            vector<vector<ll> > dp(n+2,vector<ll>(k+2));
            for(int i=0;i<=n+1;i++)
                for(int j=0;j<=k+1;j++)
                    dp[i][j] = 0;

            for(int i=0;i<=k;i++)
                dp[1][i] = 1;
            dp[1][0] = k;

            for(int i=2;i<=n;i++){
                for(int j=1;j<=k;j++){
                    // len = i, ends with j
                    dp[i][j] = dp[i-1][0];
                    for(int l=j+j;l<=k;l+=j)
                        dp[i][j] -= (dp[i-1][l])%mod;
                    dp[i][j] = (mod+dp[i][j])%mod;
                    dp[i][0] = (dp[i][0] + dp[i][j])%mod;
                }
            }
            ll sum = 0;
            for(int i=1;i<=k;i++)
                sum += dp[n][i];
            return sum%mod;
        }
};

// int main(){
//     DivFreed2 obj;
//     int a,b;    cin >> a >> b;
//     cout << obj.count(a,b) << '\n';

//     return 0;
// }