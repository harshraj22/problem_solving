// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/suffix-arrays/practice-problems/algorithm/difdif/

#include<bits/stdc++.h>
using namespace std;

#define ll long long int 

vector<int> suffixArray, lcpArray, lexOrder;

string s;	ll n;

void buildSuffixArray() {
	suffixArray.resize(n);
	lexOrder.resize(n);
	/* 
		Initialise suffixArray and lexOrder array
		for each gram:
			1. Sort the suffixArry 
			2. Calcuate temp
			3. Re-calculate the lexOrder

	*/

	vector<int> temp(n, 0);

	for (int i = 0; i < n; i += 1) {
		suffixArray[i] = i;
		lexOrder[i] = s[i] - 'a';
	}

	int gram = 1;

	auto suffCmp = [&](int i, int j)->bool {
		// returns if ar[i] < ar[j]
		if (lexOrder[i] != lexOrder[j])
			return lexOrder[i] < lexOrder[j];
		i += gram;	j += gram;
		if (i < n && j < n)
			return lexOrder[i] < lexOrder[j];
		return i > j;
	};

	for ( ; ; gram *= 2) {
		sort(suffixArray.begin(), suffixArray.end(), suffCmp);

		// temp[i] stores the lexographic order of array at 
		// index 'i' in suffixArray
		for (int i = 0; i < n - 1; i += 1) {
			temp[i+1] = temp[i] + suffCmp(suffixArray[i], suffixArray[i+1]);
		}

		// lexOrder[i] stores lexographic rank of suffix 
		// at index 'i' in the input string
		for (int i = 0; i < n; i += 1)
			lexOrder[suffixArray[i]] = temp[i];

		if (temp.back() == n-1)
			break;
	}
}

void buildLCPArray() {
	lcpArray.resize(n);
	lcpArray[suffixArray[0]] = n + 1;

	int len = 0;
	for (int i = 0; i < n; i += 1) {
		if (lcpArray[i] == n + 1) {
			lcpArray[i] = 0;
			continue;
		}

		int prev = suffixArray[lexOrder[i]-1];
		while(i+len < n && prev+len < n && s[i+len] == s[prev+len])
			len += 1;
		lcpArray[i] = len;
		len = max(0, len-1);
	}
}

void print(auto &s, auto &arr) {
	cerr << s ;
	for (auto it:arr)
		cerr << it << ' ';
	cerr << '\n';
}

int main() {

	cin >> s;
	n = s.size();

	buildSuffixArray();
	buildLCPArray();
	cout << (n*(n+1))/2 - accumulate(lcpArray.begin(), lcpArray.end(), 0LL) << '\n';

	// print("suffix array: ", suffixArray);
	// print("lcp array: ", lcpArray);

	return 0;
}