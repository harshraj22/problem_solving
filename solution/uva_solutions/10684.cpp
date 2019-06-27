// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=649&page=show_problem&problem=1625
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);	cout.tie(0);
int n,i;
cin>>n;
while(n){
vector<int> v(n);
int mx=0,mx_so=0;
for(i=0;i<n;i++)
	cin>>v[i];
for(i=0;i<n;i++){
	mx+=v[i];
	mx_so=max(mx_so,mx);
	mx=(mx<0?0:mx);
}
if(mx_so)
	cout<<"The maximum winning streak is "<<mx_so<<".\n";
else cout<<"Losing streak.\n";

	cin>>n;
}

	return 0;
}