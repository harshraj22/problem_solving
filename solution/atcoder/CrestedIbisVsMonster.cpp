// https://atcoder.jp/contests/abc153/tasks/abc153_e

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int H=1e4+2,N=1e3+4;
ll dp[H][N],n,h;
vector<ll> a,b;

void pre(){
    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }
}

ll recur(ll h, ll ind){
    if(h > 0 && ind < 0)
        return 1e10;
    else if(h<=0)
        return 0;
    else if(dp[h][ind] != -1)
        return dp[h][ind];
    
    return dp[h][ind] = min(b[ind]+recur(h-a[ind],ind), recur(h,ind-1));

}

void solve(){
    pre();
    cin >> h >> n;
    a.resize(n);    b.resize(n);
    for(int i=0;i<n;i++)
        cin >> a[i] >> b[i];

    cout << recur(h,n-1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test=1;
    // cin >> test;
    while(test--)
        solve();
    
    return 0;
}
