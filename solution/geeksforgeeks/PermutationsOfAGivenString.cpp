// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>
#define all(x) x.begin(), x.end()

string s; int n;
set<string> words;

bool isSet(int num, int bit) {
    return num & (1LL << bit);
}

int countBits(int num) {
    int Count = 0;
    for (int i = 0; i < 7; i += 1) 
        Count += isSet(num, i);
    return Count;
}

void recur(string str, int mask) {
    if (countBits(mask) == s.size()) {
        words.insert(str); return;
    }

    for (int i = 0; i < s.size(); i += 1) {
        if (!isSet(mask, i)) {
            recur(str+string(1, s[i]), mask | (1LL << i));
        }
    }
}

void solve(){
    cin >> s;
    n = s.size(); 
    words.clear();

    recur("", 0);

    for (auto word: words)
        cout << word << ' ';
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