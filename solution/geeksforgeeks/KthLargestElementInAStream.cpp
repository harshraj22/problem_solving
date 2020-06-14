// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0
// Priority Queue Using Min Heap

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

void solve(){
    int n, k;   cin >> k >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i += 1) {
        int num;    cin >> num;
        pq.push(num);
        if (pq.size() < k) 
            cout << -1 << ' ';
        else {
            while (pq.size() > k)
                pq.pop();
            cout << pq.top() << ' ';
        }
    }

    cout << endl;
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