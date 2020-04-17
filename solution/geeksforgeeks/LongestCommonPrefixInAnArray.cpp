// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0

#include<bits/stdc++.h>
using namespace std;

struct node{
    unordered_map<char, node*> transition;
};

node* getNode() {
    return new node();
}

node* head;
int ans = 0;

void inline insert(node* root, string& s, int pos=0) {
    if (root->transition.size() > 1)
        return;
    
    if (pos == s.size()) {
        root->transition['$'] = getNode();
        return;
    }
    char ch = s[pos];
    if (root->transition.find(ch) == root->transition.end())
        root->transition[ch] = getNode();

    insert(root->transition[ch], s, pos+1);
}

void inline query(node* root) {
    if (root->transition.size() != 1)
        return;
    ans += 1;
    query(root->transition.begin()->second);
}

void inline solve() {
    int n;  cin >> n;
    ans = 0;
    head = getNode();
    string s;   
    for (int i = 0; i < n; i += 1) {
        cin >> s;
        insert(head, s);
    }
    
    query(head);

    if (ans > 0)
        cout << s.substr(0, ans) << '\n';
    else 
        cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test = 1;
    cin >> test;
    while(test--)
        solve();

    return 0;
}