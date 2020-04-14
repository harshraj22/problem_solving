// https://www.spoj.com/problems/SARRAY/
// Basic nlog^2n Suffix Array solution
// Problem mentioned it should get 40 pts, but I am amazed to see 
// it getting 100 pts.!

#include<bits/stdc++.h>
using namespace std;

string inputString;
/*
    suffixArray[i] stores index of suffix (of inputString) that
        lies at rank 'i' when all suffixes are sorted
    lexoRank[i] stores the lexographic rank of suffix at index 'i'
        (in the inputString) i.e. inputString.substr(i)
*/
vector<int> suffixArray, lexoRank;
int n;

void buildSuffixArray() {
    suffixArray.resize(n);
    lexoRank.resize(n);

    // initialize the suffixArray and lexoRank
    for (int i = 0; i < n; i += 1) {
        lexoRank[i] = inputString[i];
        suffixArray[i] = i;
    }

    int gram = 1;
    // while gram < n
    //      1. Sort the suffixArray
    //      2. re-calculate lexoRank    
    auto suffCmp = [&](int i, int j)->bool{
        if (lexoRank[i] != lexoRank[j])
            return lexoRank[i] < lexoRank[j];
        i += gram;  j += gram;
        if (i < n && j < n)
            return lexoRank[i] < lexoRank[j];
        return i > j;
    };

    for ( ; ; gram *= 2) {
        // sort the suffixArray
        sort(suffixArray.begin(), suffixArray.end(), suffCmp);

        // re-calculate lexoRank
        vector<int> temp(n, 0);

        for (int i = 1; i < n; i += 1) {
            int cur = suffixArray[i], prev = suffixArray[i-1];
            temp[cur] = temp[prev] + suffCmp(suffixArray[i-1], suffixArray[i]);
        }

        for (int i = 0; i < n; i += 1)
            lexoRank[i] = temp[i];

        if (*max_element(temp.begin(), temp.end()) == n-1)
            break;        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> inputString;
    n = inputString.size();

    buildSuffixArray();
    
    for (auto it: suffixArray)
        cout << it << '\n';

    return 0;
}