// https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool pre(vector<int> &v, int l, int r) {
	r = min(r, (int)v.size());
    if (r-l <= 1)
        return true;
    int i = l;
    while(i <= r && v[i] <= v[l])
        i += 1;
    for (int var = i; var <= r; var += 1) {
        if (v[var] <= v[l])
            return false;
    }
    return min(pre(v, l+1, i-1), pre(v, i, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int test; cin >> test;
	while(test--) {
	    int n;  cin >> n;
	    vector<int> v(n);
		for (auto &it:v)
			cin >> it;
	    cout << pre(v, 0, n-1) << '\n';
	}
	
	return 0;
}