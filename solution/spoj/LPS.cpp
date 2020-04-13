// https://www.spoj.com/problems/LPS/
// O(n) solution using Manacher's algo for longest palindromic subsegment
#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr) {
    for (auto it:arr)
        cerr << it << ' ';
    cerr << '\n';
}

// gives lenght of longest odd length palindrome
int getLen(string s, bool evenLength = false) {
    // if we want to find even length palindrome,
    // manipulate the input string, and find odd length
    if (evenLength) {
        string res; res += '\0';
        for (auto ch:s) {
            res += ch;
            res += '\0';
        } 
        swap(res, s);
    }

    // [left, right] denotes the current largest palindrome
    // such that i <= right
    int n = s.size(), left = 1, right = 1;
    vector<int> pal(n, 0);

    for (int i = 1; i < n; i += 1) {
        int dist = right - i, mirror = left + dist;
        int len = min(pal[mirror], mirror-left+1);

        while(i-len >= 0 && i+len < n && s[i-len] == s[i+len])
            len += 1;
        
        pal[i] = len - 1;
        if (right < i + len - 1) {
            right = i + len - 1;
            left = i - len + 1;
        }
    }

    // printArr(pal);
    
    int oddWing = *max_element(pal.begin(), pal.end());
    if (evenLength) 
        return oddWing;
    return oddWing*2 + 1;
}

int main() {
    int n;  cin >> n;
    string s;   cin >> s;
    cout << max(getLen(s, false), getLen(s, true)) << '\n';

    return 0;
}