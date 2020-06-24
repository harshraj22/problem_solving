// https://www.geeksforgeeks.org/trapping-rain-water/
// Time: O(n)
// Space: O(n), can be improved to O(1) as for each i, we only use values of suff[i], pref[i]

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size(), water = 0;
    vector<int> pref(n), suff(n);

    for (int i = 1; i < n; i += 1) 
        pref[i] = max(pref[i-1], height[i-1]);

    for (int i = n-2; i >= 0; i -= 1)
        suff[i] = max(suff[i+1], height[i+1]);

    for (int i = 1; i+1 < n; i += 1) {
        int h = min(pref[i], suff[i]);
        water += max(0, h-height[i]);
    }

    return water;
}

int main() {
    int test;   cin >> test;
    while (test--) {
        int n;  cin >> n;
        vector<int> height(n);
        for (auto &it: height)
            cin >> it;
        cout << trap(height) << '\n';
    }

    return 0;
}

