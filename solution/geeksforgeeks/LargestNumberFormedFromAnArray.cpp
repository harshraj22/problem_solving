// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

void solve(){
    int n;  cin >> n;
    vector<string> nums(n);
    for (auto &num: nums)
        cin >> num;

    sort(all(nums), [](string a, string b){ return a+b < b+a; });
    reverse(all(nums));
    cout << accumulate(all(nums), string()) << '\n';
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