#include<bits/stdc++.h>
using namespace std;

int fun(int val);
vector<int> v;
int n,c;

int main(){
ios_base::sync_with_stdio(false);
int test;
cin>>test;
while(test--){
	int k,j,i,m;
	cin>>n>>c;
	v.resize(n);
	for(i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	int low=0,high=v[n-1];
	while(low<high){
		int mid=low+(high-low)/2;
		if(fun(mid))
			low=mid+1;
		else high=mid;
	}
	cout<<max(low-1,0)<<endl;
}

	return 0;
}

int fun(int val){
	int cnt=1,prev=v[0];
	for(int i=0;i<n;i++){
		if(v[i]-prev>=val){
			prev=v[i];
			cnt++;
		}
		if(cnt==c)
			return 1;
	}
	return 0;
}