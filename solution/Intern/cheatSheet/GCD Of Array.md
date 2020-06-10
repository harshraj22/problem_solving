Question [Link](https://practice.geeksforgeeks.org/problems/gcd-of-array/0)


Time: O(logn) for gcd, overall O(T * n * logn)
Space: O(logn) for gcd -Recursion, overall O(logn)

Idea Used: Basic GCD formula

```c++
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

int gcd(int g, int var) {
    if (g == 0) return var;
    return gcd(var%g, g);
}

void solve() {
    int g = 0, n;   cin >> n;
    for (int i = 0; i < n; i += 1) {
        int var;   cin >> var;
        g = gcd(g, var);
    }

    cout << g << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int test = 1;
    cin >> test;
    while(test--)
        solve();
    
    return 0;
}
```
