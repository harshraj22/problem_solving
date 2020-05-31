// https://practice.geeksforgeeks.org/problems/inversion-of-array/0/
// Counting Inversion: O(nlogn) Time, O(nlogn) space: O(n) space at each depth for merge, can be optimised

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

ll ans = 0, n = 0;

void invCount(int left, int right, vector<ll> &v) {
    if (left == right) return;
    int mid = (left + right)/2;
    invCount(left, mid, v);
    invCount(mid+1, right, v);

    // for each i in [left, mid] count num of elements less than a[i] in [mid+1, right]
    for (int i = left; i <= mid; i += 1) {
        ans += lower_bound(v.begin()+mid+1, v.begin()+right+1, v[i]) - (v.begin()+mid+1);
    }

    // sort(v.begin()+left, v.begin()+right+1);
    vector<ll> var(v.begin()+left, v.begin()+mid+1);
    var.push_back(1LL + 1e18); 
    int first = mid+1, second = 0;

    for (int i = left; i <= right; i += 1) {
        if (first <= right && v[first] < var[second]) {
            v[i] = v[first]; first += 1;
        }
        else {
            v[i] = var[second]; second += 1;
        }
    }
}

void solve(){
    ans = 0; cin >> n;
    vector<ll> v(n);
    for (auto &it: v) cin >> it;
    invCount(0, n-1, v);

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