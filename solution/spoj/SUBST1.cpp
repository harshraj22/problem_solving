// https://www.spoj.com/problems/SUBST1/
// Most Basic problem of suffixArray

#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

string s; ll n;
/* 
    suffixArray[i] stores the index of suffix (index 
    in the input string) that would be at position 'i'
    if all possible suffixes were sorted.
    lcpArray[i] number of chars matched by a suffix at 
    index 'i' in the given string with the suffix that 
    comes just before it in suffix array (ie. which preceeds
    it when all suffixes are sorted)
    lookBack[i] stores the lexographic rank of suffix 
    at index 'i' in the given string. If two strings
    have all chars same (possible when comparing only 
    first few chars), their lexographic rank is same
*/
vector<int> suffixArray, lcpArray, lookBack;

void buildSuffixArray() {
    // builds the suffix array

    lookBack.resize(n);

    // temp[i] stores lexographic rank of suffix at index
    // 'i' in the suffix array
    vector<int> temp(n, 0);

    // initialise suffixArray and lookBack
    for (int i = 0; i < n; i += 1) {
        suffixArray[i] = i;
        lookBack[i] = s[i] - 'a';
    }

    int step = 1, gram = 1;
    /*  
        For each gram, we do 2 steps:
            1. Sort the suffix array
            2. Re-calculate the lookBack table
    */
    
    for ( ; ; gram *= 2) {
        auto compSuffix = [&](int i, int j) -> bool {
            // checks if suffix at 'i' < suffix at 'j' using
            // first 'gram' number of chars only
            if (lookBack[i] != lookBack[j])
                return lookBack[i] < lookBack[j];
            i += gram;  j += gram;
            return (i<n && j<n) ? lookBack[i] < lookBack[j] : i > j;
        };

        // for each gram (1 gram = first 2^1 chars)
        sort(suffixArray.begin(), suffixArray.end(), compSuffix);

        // now suffixArray is sorted as per 'gram' number of chars
        // lookBack contains lookup as per 'gram-1' chars

        for (int i = 0; i < n - 1; i += 1) {
            // for each suffix in suffixArray, calculate the rank
            temp[i+1] = temp[i] + compSuffix(suffixArray[i], suffixArray[i+1]);
        }

        // now re-calculate lookBack table
        for (int i = 0; i < n; i += 1) {
            lookBack[suffixArray[i]] = temp[i];
        }

        // if all ranks are distinct, there is time to terminate 
        if (temp.back() == n-1)
            break;
    }
}

void buildLCPArray() {
    // prev[i] stores index of suffix in the string
    // which lies just above (in the suffix array) 
    // the suffix at index 'i' in the string
    vector<int> prev(n);
    int len = 0;

    // the string that lies at the top in suffix array,
    // before it, we can have only empty string as suffix
    prev[suffixArray[0]] = n;

    for (int i = 1; i < n; i += 1)
        prev[suffixArray[i]] = suffixArray[i-1];

    // lcpArray[i] stores lcp for suffix starting at index
    // 'i' in given string
    // lcp = number of chars matching in prefixes of two strings

    for (int i = 0; i < n; i += 1) {
        if (prev[i] == n) {
            lcpArray[i] = 0;
            continue;
        }
        // count number of matching char in suffix starting
        // at index 'i' in givens string and the suffix
        // starting at index 'prev[i]'

        // for current suffix, match with the suffix occuring 
        // just before it in suffixArray

        while(i+len<n && prev[i]+len<n && s[i+len] == s[prev[i]+len])
            len += 1;
        lcpArray[i] = len;

        // this is important to observe, suppose suffix at index 'i'
        // (in the string) was compared with suffix at index 'j' (in 
        // the string) and had lcp = len. The suffix at index 'i+1'
        // will have lcp value at least 'len+1', (the value len+1 is 
        // obtained with the suffix starting at index 'j+1')
        len = max(len-1, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test;   cin >> test;
    while(test--) {

        cin >> s;   n = s.size();

        suffixArray.resize(n);
        lcpArray.resize(n);

        buildSuffixArray();
        buildLCPArray();

        // total possible substrings - number of repeating substrings
        cout << (n*(n+1))/2 - accumulate(lcpArray.begin(), lcpArray.end(), 0LL) << '\n';

        // remember, lcp of two suffixes give number of matching chars 
        // in the prefixes each will form a substring
    }

    return 0;
}