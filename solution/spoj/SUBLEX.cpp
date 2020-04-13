// https://www.spoj.com/problems/SUBLEX/
// O(nlog^2(n)) suffix array solution

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

string inputString;
int n;
/*
    suffixArray[i] stores the index of suffix (index in inputString)
        which lies at index 'i' when all suffixes (of inputString)
        are sorted
    lcpArray[i] stores number of first characters matched between
        suffix at index[i] in the suffixArray and the suffix at index
        i-1 in suffixArray
    lexOrder[i] stores the lexographic rank of suffix at index i (the
        suffix of inputString)
*/
vector<int> suffixArray, lcpArray, lexOrder, prefSum;

void buildSuffixArray() {
    // builds the suffixArray
    suffixArray.resize(n);
    lexOrder.resize(n);

    // initialize with default values
    for (int i = 0; i < n; i += 1) {
        suffixArray[i] = i;
        lexOrder[i] = inputString[i] - 'a';
    }

    // the number of char to be taken into consideration
    // while comparing two substrings
    int gram = 1;
    // custom function to compare two substrings
    // returns if inputString.substr(i) < inputString.substr(j)
    auto suffCmp = [&](int i, int j)->bool{
        if (lexOrder[i] != lexOrder[j])
            return lexOrder[i] < lexOrder[j];
        i += gram;  j += gram;
        if (i < n && j < n)
            return lexOrder[i] < lexOrder[j];
        return i > j;
    };

    for ( ; ; gram *= 2) {
        // sort the suffixArray based on first 'gram' number of chars
        sort(suffixArray.begin(), suffixArray.end(), suffCmp);

        // temp[i] contains lexographic Rank of suffix at index i in 
        // suffixArray
        vector<int> temp(n, 0);
        for (int i = 0; i + 1 < n; i += 1) {
            temp[suffixArray[i+1]] = temp[suffixArray[i]] + suffCmp(suffixArray[i], suffixArray[i+1]);
        }

        // re-calculate the lexOrder
        for (int i = 0; i < n; i += 1) {
            int curSuffIndex = suffixArray[i];
            int curSuffRank = temp[curSuffIndex];
            lexOrder[curSuffIndex] = curSuffRank;
        }

        if (*max_element(temp.begin(), temp.end()) == n-1)
            break;
    }
}

void buildLcpArray() {
    // builds the lcpArray
    lcpArray.resize(n, 0);

    int len = 0;
    for (int i = 0; i < n; i += 1) {
        if (lexOrder[i] == 0) {
            lcpArray[i] = 0;
            continue;
        }

        // index of suffix (in the inputString) that lies just above
        // the current rendering suffix 
        int prev = suffixArray[lexOrder[i]-1];
        // one thing to note is lcpArray[inputString.substr(i)] will be atleast
        // lcpArray[inputString.substr(i-1)]
        while(i+len < n && prev+len && inputString[i+len] == inputString[prev+len])
            len += 1;

        lcpArray[i] = len;
        len = max(len-1, 0);
    }
}

void printArr(string s, vector<int>& arr) {
    // print to error stream, debugging
    cerr << s << ": ";
    for (auto it: arr)
        cerr << it << ' ';
    cerr << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> inputString;
    n = inputString.size();

    buildSuffixArray();
    buildLcpArray();

    prefSum.resize(n, 0);
    for (int i = 0; i < n; i += 1) {
        // index is index of suffix in inputString lying at position 'i'
        // in suffixArray
        int index = suffixArray[i];
        // n - index is inputString.substr(index)
        // we remove lcpArray[index], this gives number of distinct substrings
        // that can be formed starting at index='index' of inputString
        prefSum[i] = (n - index) - lcpArray[index];
    }

    // we store the cummulative sum, now this array is monotonic
    for (int i = 1; i < n; i += 1)
        prefSum[i] += prefSum[i-1];

    // printArr("lcpArray", lcpArray);
    // printArr("suffixArray", suffixArray);
    // printArr("lexOrder", lexOrder);
    // printArr("prefSum", prefSum);

    int queries;    cin >> queries;
    while(queries--) {
        int k;  cin >> k;
        // find first index 'prefIndex' where prefSum[prefIndex] >= k
        int prefIndex = lower_bound(prefSum.begin(), prefSum.end(), k) - prefSum.begin();
        // suffIndex gives the index of suffix in inputString, that is denoted by prefSum[prefIndex]
        // size is the size of that suffix
        int suffixIndex = suffixArray[prefIndex], size = n - suffixIndex;
        // suppose prefIndex = [5,10,15,20] and k = 7, then prefIndex = 1,
        // prefSum[prefIndex] - k = 3, that is, remove the last 3 chars of 
        // inputString.substr(suffixIndex) to get answer
        int revOffset = size - (prefSum[prefIndex] - k);

        string ans = inputString.substr(suffixIndex, revOffset);
        cout << ans << '\n';
    }

    return 0;
}