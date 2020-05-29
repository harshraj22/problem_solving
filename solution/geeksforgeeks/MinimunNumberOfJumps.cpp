// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e7+3;

ll jump[N],step[N],n;

ll res(ll ind){
    // assert(ind < N);
    // assert(ind < 0);
    
    if(ind >= n-1 || ind < 0)
        return 0;
    else if(jump[ind] != -1)
        return jump[ind];
    ll minStep = N+4;
    if(step[ind] == 0)
        return jump[ind] = minStep;
    for(ll i=ind+1;i<=ind+step[ind];i++)
        minStep = min(minStep,1+res(i));
    return jump[ind] = minStep;
}

void solve(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> step[i];
        jump[i] = -1;
    }
    ll result = res(0);
    // assert(n < N);
    if(result > N)
        cout << -1 << endl;
    else
        cout << result << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--)
        solve();
	
	return 0;
}