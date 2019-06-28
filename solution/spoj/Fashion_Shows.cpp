#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);		cout.tie(0);
ll test;
cin>>test;
while(test--){
	ll i,j,k,n,m=0;
	cin>>n;
	vector<ll> v(n),fe(n);
	for(i=0;i<n;i++)
		cin>>v[i];
	for(i=0;i<n;i++)
		cin>>fe[i];
	sort(v.begin(),v.end());
	sort(fe.begin(),fe.end());
	for(i=0;i<n;i++)
		m+=v[i]*fe[i];
	cout<<m<<"\n";
}
	return 0;
}