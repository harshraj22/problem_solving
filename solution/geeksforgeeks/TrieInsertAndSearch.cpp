// https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0

#include<bits/stdc++.h>
using namespace std;

struct node{
    map<char, node*> transition;
    bool completed = false;
};

node* head;

node* getNode() {
    return new node();
}

void insert(node* root, string& s, int pos = 0) {
    if (pos == s.size()) {
        root->completed = true;
        return ;
    }
    char ch = s[pos];
    if (root->transition.find(ch) == root->transition.end())
        root->transition[ch] = getNode();
    insert(root->transition[ch], s, pos+1);
}
bool search(node* root, string& s, int pos = 0) {
    if (pos == s.size()) {
        return root->completed;
    }
    char ch = s[pos];
    if (root->transition.find(ch) == root->transition.end())
        return false;
    return search(root->transition[ch], s, pos+1);
}

void solve() {
    head = getNode();
    int n;  cin >> n;
    string s;
    for (int i = 0; i < n; i += 1) {
        cin >> s;
        insert(head, s);
    }

    cin >> s;
    cout << search(head, s) << '\n';
}

int main() {
    int test = 1;
    cin >> test;
    while(test--)
        solve();

    return 0;
}