// https://acm.timus.ru/problem.aspx?space=1&num=1297

//=====================COMPILER OPTIMIZATION STARTS=======================
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
//======================COMPILER OPTIMIZATION ENDS=======================

//compile using : g++ -D DEB file.cpp
#ifdef DEB
	//to check from out of bounds errors
	#define _GLIBCXX_DEBUG
#endif
//=============================DEBUG PART ENDS===========================

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<ll,ll>

ll power(ll x, ll y, ll mod = 1e9+7){
	ll res = 1;
	while(y > 0){
		if(y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x*x)% mod;
	}
	return res % mod;
}

string palindrome(string a, bool oddLength) {
    // bool oddLength tells if we need to find the largest
    // odd length palindrome in the string 'a'
	string s;
	if (!oddLength) {
		s = "#";
		for (auto ch:a) {
			s += ch;
			s += '#';
		}
	}
	else {
		s = a;
	}
	
	// now find the lenght of longest odd lenght palindrome
	// in string s
	int n = s.size(), l = 0, r = -1;

    // len[i] stores number of characters to one side
    // of the odd length palindrome centered at 'i'
	vector<int> len(n, 0);

    // standard code for manacher's algo
    // range [l, r] tells the range of palindrom found till now
    // with largest right end
	for (int i = 1; i < n-1; i += 1) {
		int j = 0;
		if (i > r) {
			j = 0;
		}
		else {
			int k = r - i;
			j = min(len[l+k], k);
		}
		while(i+j<n && i-j>=0 && s[i-j]==s[i+j])
			j += 1;
		len[i] = j - 1;
	}

	string ans = "", sol="";
	int index = max_element(len.begin(), len.end()) - len.begin();

	ans = s.substr(index-len[index], 1+2*len[index]);

    // if we included '#' in string, remove it
	for (auto ch:ans) {
		if (ch != '#')
			sol += ch;
	}

	return sol;
}

void solve(){
	string s;	cin >> s;
	string odd = palindrome(s, true), even = palindrome(s, false);
	if (odd.size() > even.size())	
		cout << odd << '\n';
	else 
		cout << even << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test = 1;
	// cin >> test;
	while(test--)
		solve();
	return 0;
}