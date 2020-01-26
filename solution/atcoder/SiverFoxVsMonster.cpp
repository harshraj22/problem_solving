// https://atcoder.jp/contests/abc153/tasks/abc153_f

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    ll n,d,a;
    cin >> n >> d >> a;
    vector<pi> v(n);
    for(auto &it:v)
        cin >> it.first >> it.second;

    sort(v.begin(),v.end());
    map<ll,ll> mp;
    ll ans=0,sum=0;
    for(auto it:v){
        sum += mp[it.first];
        ans += ceil(max(0LL,it.second-sum)*1.0/a);
        ll val = lower_bound(v.begin(),v.end(),make_pair(it.first+2*d+1,0LL))-v.begin();
        if(val < n)
            mp[v[val].first] -= a*ceil(max(0LL,it.second-sum)*1.0/a);
        sum += a*ceil(max(0LL,it.second-sum)*1.0/a);
    }
    cout << ans << '\n';
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
