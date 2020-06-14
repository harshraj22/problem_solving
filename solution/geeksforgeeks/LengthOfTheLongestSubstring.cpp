// https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring/0
// Two Pointers based solution 
// Time: O(nlogn)
// Space: O(n)

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

void solve(){
    string s;   cin >> s;
    map<char, int> freq;
    int left = 0, right = 0, ans = 0;

    while (right < s.size()) {
        while (freq[s[right]] != 0) {
            freq[s[left]] -= 1;
            left += 1;
        }
        freq[s[right]] += 1;
        right += 1;
        ans = max(ans, right-left);
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