// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0/
// Heap based good problem
// Note: push_up and push_down can be implemented iteratively to remove usage of recursion memory stack

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

int leftChild(int node) {
    return node*2 + 1;
}

int rightChild(int node) {
    return node*2 + 2;
}

int parent(int node) {
    return node/2 + 1 - node%2;
}

void push_up(vector<int> &v, int index) {
    // pushes element up the tree to ensure min heap property is maintained
    int par = parent(index);
    if (index == 0 || v[par] <= v[index])
        return;
    swap(v[par], v[index]);
    push_up(v, par);
}

void push_down(vector<int> &v, int index) {
    // pushes element down the tree to ensure min heap property is maintained
    int left = leftChild(index), right = rightChild(index);
    for (auto child: {left, right}) {
        if (v.size() <= child)
            continue;
        else if (v[index] > v[child]) {
            swap(v[index], v[child]);
            push_down(v, child);
        }
    }
}

vector<int> arranged(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    // convert b into min_heap
    for (int i = m-1; i > 0; i -= 1) 
        push_up(b, i);

    // put first smallest n nums in a, and rest in b
    for (auto &num: a) {
        if (num < b[0]) {
            swap(num, b[0]);
            push_down(b, 0);
        }
    }

    // sort a and b and store it in a vector and return
    sort(all(a)); sort(all(b));
    // return after adding two 
    
    // a.insert(a.end(), b.begin(), b.end());
    vector<int> ans(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
    return ans;
}

void solve(){
    int x, y;   cin >> x >> y;
    vector<int> arr1(x), arr2(y);
    for (auto &it: arr1) cin >> it;
    for (auto &it: arr2) cin >> it;
    
    for (auto num: arranged(arr1, arr2))
        cout << num << ' ';
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