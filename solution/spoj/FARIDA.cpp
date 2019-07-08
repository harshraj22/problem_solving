//	https://www.spoj.com/problems/FARIDA/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);	cout.tie(0);
int test;	cin>>test;
for(int ii=1;ii<=test;ii++){
	ll i,j,k,n,m;
	cin>>n;	vector<ll> v(n);
	if(n==0){
		cout<<"Case "<<ii<<": "<<"0\n";
		continue;
	} 
	ll sum[2][n]={0};
	for(i=0;i<n;i++){
		cin>>v[i];
		if(i==0)sum[1][i]=v[i];
		else{
			sum[1][i]=sum[0][i-1]+v[i];
			sum[0][i]=max(sum[0][i-1],sum[1][i-1]);
		}
	}
	cout<<"Case "<<ii<<": "<<max(sum[1][n-1],sum[0][n-1])<<"\n";
}
	return 0;
}