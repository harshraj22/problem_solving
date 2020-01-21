// read editorial for detailed explaination
// https://codeforces.com/problemset/problem/1148/B

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll n,m,k,ta,tb;
vector<ll> a,b;

// given num of deleted flights from a, returns the min time when it can reach taking flights from b
// if it can't take, prints -1 and terminates programme
ll check(ll arrival,ll deleted){
    // num of flights that can be deleted in b
    ll left = k-deleted;
    int index = lower_bound(b.begin(),b.end(),arrival)-b.begin();
    index += left;

    if(index >= m){
        // if all the remaining flights can be deleted
        cout << "-1\n";
        exit(0);
    }

    return b[index]+tb;
}

int main(){
    cin >> n >> m >> ta >> tb >> k;
    a.resize(n);    b.resize(m);

    for(auto &it:a)
        cin >> it;
    for(auto &it:b)
        cin >> it;

    if(k >= n || k >= m){
        // if all flights of 'a' or 'b' can be deleted
        cout << "-1\n";
        return 0;
    }
    ll ans = 0;
    for(int i=-1;i<k;i++){
        // remove first i+1 from 'a'
        ans = max(ans, check(a[i+1]+ta,i+1));
    }

    cout << ans << '\n';
    return 0;
}