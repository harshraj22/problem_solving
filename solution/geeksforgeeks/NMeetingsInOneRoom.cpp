// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
// Interval Scheduling

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

void solve(){
    int n, ans = 0, last = -1; cin >> n; 
    vector<pair<int, int>> activities(n);
    for (auto &it: activities)
        cin >> it.first;
    for (auto &it: activities)
        cin >> it.second;
    
    auto cmp = [](pair<int, int> &p1, pair<int, int>&p2)->bool{
        // returns if p1 < p2
        if (p1.second != p2.second)
            return p1.second < p2.second;
        return p1.first < p2.first;
    };

    // sort based on earliest finish time
    sort(activities.begin(), activities.end(), cmp);

    for (auto it: activities) {
        if (it.first >= last) {
            ans += 1; last = it.second;
        }
    }

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