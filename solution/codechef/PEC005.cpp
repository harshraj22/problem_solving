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

void solve(){
	int n, ans = 0;	cin >> n;
	vector<long long int> v(n), LIS(n, 1e10);
	for (auto &it:v)
		cin >> it;

	for (auto it:v) {
		// for each element in input array, find element
		// just less than or equal to it in LIS array
		int index = upper_bound(LIS.begin(), LIS.end(), it) - LIS.begin() - 1;

		LIS[index+1] = it;
		ans = max(ans, index+1);
	}

	cout << ans + 1<< '\n';
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
from bisect import bisect_right, bisect_left

tests = int(input())
for test in range(tests):
    n, ans = int(input().strip()), 0
    arr = list(map(int, input().strip().split()))
    lis = [inf for i in arr]

    for element in arr:
        # for each element, find element in lis array
        # which is just less than or equal to current
        # iterating element

        # bisect_right returns index of the place where
        # current element should be inserted so that
        # array lis remains sorted, if 'element' is already
        # present is the sorted array lis, it returns the
        # next index of rightmost occurence of 'element'
        index = bisect_right(lis, element) - 1

        # 'index' is the position where value of element
        # is lessthan or equal to the currently iterating element

        lis[index+1] = element
        ans = max(ans, index+1)
        
    # as indexing started from 0, answer will have to add 1
    print(ans + 1)

 */