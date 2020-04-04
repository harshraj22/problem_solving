// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
    int n;  cin >> n;
    vector<int> v(n);
    for (auto &it:v)
        cin >> it;
    ll cur_sum = 0, max_sum = INT_MIN, left = 0, right = 0;
    while (right < n) {
        while (cur_sum < 0 && left < right) {
            cur_sum -= v[left];
            left += 1;
        }
        cur_sum += v[right];
        right += 1;
        max_sum = max(max_sum, cur_sum);
    }
    
    while (left + 1< right) {
        cur_sum -= v[left];
        max_sum = max(max_sum, cur_sum);
        left += 1;
    }
        
    cout << max_sum << '\n';
}

int main(){
	int test = 1;
	cin >> test;
	while(test--)
	    solve();
	
	return 0;
}