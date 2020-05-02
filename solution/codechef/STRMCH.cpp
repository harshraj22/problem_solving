// https://www.codechef.com/problems/STRMCH
// An Awesome KMP + Binary Search Based Solution
// Time: O(nlogn) space: O(n)
// Binary Search the length of longest prefix

// Hint from: https://www.codechef.com/viewsolution/10811621

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

int n, k; string s;

bool possible (int len) {
    string target = s.substr(0,len) + "#" + s;
    int n = target.size(), freq = 0;
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i += 1) {
        int prev = lps[i-1];
        while(prev && target[prev] != target[i]) 
            prev = lps[prev-1];
        if (target[prev] == target[i])
            prev += 1;
        lps[i] = prev;
        freq += (lps[i] >= len);
    }
    return freq >= k;
}

void solve(){
    cin >> n >> s >> k;
    int low = 0, high = n;
    while(low < high) {
        int mid = (low + high + 1)/2;
        if (possible(mid))
            low = mid;
        else 
            high = mid - 1;
    }
    
    cout << low << '\n';
    cout << s.substr(0, low) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);	cout.tie(0);

    int test = 1;
    // cin >> test;
    while(test--)
        solve();
    return 0;
}