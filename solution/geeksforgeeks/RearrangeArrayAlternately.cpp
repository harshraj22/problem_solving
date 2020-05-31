// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0/
// Idea from YouTube
// How to store two numbers at one position
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

void print(vector<ll> &v) {
    for (auto num: v) cout << num << ' ';
    cout << endl;
}

ll get(ll num, bool first, ll large) {
    if (first) return num % large;
    return num / large;
}

ll put(ll n1, ll n2, ll large) {
    return n1 + (n2 % large) * large;
}

void solve(){
    int n;  cin >> n;
    vector<ll> nums(n);

    for (auto &it: nums) cin >> it;
    reverse(all(nums));

    // large must be greater than *max_element(all(nums))
    const ll large = 1e8;
    int first = 0, last = n-1;

    // at each index, first num is the num in original array,
    // the second num is the num in expected array
    for (int i = 0; i < n; i += 1) {
        if (i % 2 == 0) {
            // put the next max
            nums[i] = put(nums[i], get(nums[first], true, large), large);
            first += 1;
        }
        else {
            // put the next min
            nums[i] = put(nums[i], get(nums[last], true, large), large);
            last -= 1;
        }
    }

    // create the expected array
    for (auto &num: nums) 
        num = get(num, false, large);

    print(nums);
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