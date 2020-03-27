// https://codeforces.com/problemset/problem/439/D
// Idea:
//      Ternary Search.

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

/*  
    Teranry Search:
        Pre-Requisite:
            Binary Search, why and how works. 
            Definition using monotonic function.
        Intro:
            It is used to find the position of local extrema. 
            In the given graph, it gives point p.
         
         (y)|
            | \    /
            |  \  /
            |___\/______(x)
                (p)

        Implementation:
            As in case of Binary Search, we have a range of 
            x (low, high), and a evaluation function (say f),
            we keep checking mid = (low+high)/2, with f, and 
            update low or high, here we have a range of x (low, high).
            We paritition it into 2 parts (mid1 = low + (high-low)/3)
            and (mid2 = high - (high-low)/3). Remember, (high-low)/3
            gives distance between high, and low divided by 3.

            Now the cases follow:
                f(mid1) > f(mid2):
                    low shifts to mid1
                f(mid2) > f(mid1):
                    high shifts to mid2
                f(mid1) == f(mid2):
                    both shift
            (You can visualize the cases as why this follows by drawing
            graphs and pointing mid1, mid2). 
            Remember the goal is to shrink the x-range (low, high) to 
            a single point.

            Ex: 
                f(x) = y
            | 
         (y)| \          /
            |  *(mid1)  /
            |   \      *(mid2)
            |    \    /
            |     \  /
            |______\/______(x)
                   (p)

        Well,
            What is f, x in this question ?
        If min(a) has to be equal to max(b), x is the required value.
        
        Given a value, how to find number of operations required to make
        min(a) >= value and max(b) <= value ?
            That is what our function f, is doing. Check it out.

        An important point to note is, for the given f in this problem, 
        it need not hav one single point as min, eg.

         (y)|
            | \      /
            |  \    /
            |___\__/______(x)
                 (p)
        There might be a range of x, making it min, but global min is unique.

        How can you argue this ?
            Represent points of a, b as histogram, and the required value as
            a horizontal line. The claim is that value of line will be optimal
            only if num of points in a lying below line, is same as num of 
            points in b lying above line (handle corner cases like num[a] = num[b] + 1)
        Suppose not, shift the line and see the value of f decrease. Here f is 
        calculated as sum of dist of points (points of a that lie below line and points
        of b that lie above b) from value.
            
*/

// min of a >= max of b
// ie. increase a, decrease b
vector<int> a, b;
int n, m;

long long int f(int k) {
	long long int ans = 0;
	for (auto it:b) {
		if (it > k)
			ans += it - k;
	}
	for (auto it:a) {
		if (it < k) 
			ans += k - it;
	}

	return ans;
}

void solve(){
	cin >> n >> m;
	a.resize(n);	b.resize(m);
	for (auto &it:a)
		cin >> it;

	for (auto &it:b)
		cin >> it;

	long long int low = 1, high = 1e9+1;
	while (low + 2 < high) {
		long long int mid1, mid2;
		mid1 = low + (high-low)/3;
		mid2 = high - (high-low)/3;

		if (f(mid1) > f(mid2)) {
			low = mid1;
		}	else if (f(mid1) < f(mid2)) {
			high = mid2;
		}	else {
			low = mid1;
			high = mid2;
		}
	}

	while (low < high) {
		if (f(low) > f(high))
			low += 1;
		else 
			high -= 1;
	}

	cout << f(low) << '\n';
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