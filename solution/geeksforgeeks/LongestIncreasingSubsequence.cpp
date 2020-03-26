// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

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


// "end element of smaller list is smaller than end elements of larger lists"
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

void solve(){
	int n;	cin >> n;

	// lis[i] stores the last element of the increasing
	// sequence, of length 'i'
	vector<int> v(n), lis(n+1, INT_MAX);

	// input array
	for (auto &it:v)
		cin >> it;

	for (auto it:v) {
		// for each element, find the incresing sequence with
		// 		1. Longest Length
		// 		2. max element less than or equal to 'it'
		int index = lower_bound(lis.begin(), lis.end(), it) - lis.begin();

		// * Clone the found sequence, and add 'it' to its end
		// * If there exists another sequence of same length, remove it 
		// 		as we found a new sequence of same length, with smaller
		// 		largest value (if 'it' were greater, we wouldn't have 
		// 		chosen the current chosen increasing sequence)
		lis[index] = it;
	}

	int ans = 0;
	
	// find max 'i' such that, lis[i] is less than INT_MAX
	// remember what lis[i] represents
	for (; lis[ans] < INT_MAX; ans += 1) {
		// pass
	}

	cout << min(ans, n) << '\n';
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

/* 
from math import inf
from bisect import bisect_right

tests = int(input())
for test in range(tests):
    n, ans = int(input()), 0
    arr = list(map(int, input().split()))
    lis = [inf for _ in range(n)]

    for element in arr:
        # bisect_right returns the rightmost index, where 'element'
        # should be inserted for array to remain sorted, if 'element'
        # is already present, it returns the next index of rightmost 
        # position of 'element'
        index = max(-1, bisect_right(lis, element) - 1)
        
        lis[index+1] = element
        ans = max(ans, index+1)

    print(ans+1)    

 */