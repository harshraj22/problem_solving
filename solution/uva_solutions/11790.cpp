// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2890
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define mp make_pair

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);		cout.tie(0);
int test;
cin>>test;
for(ll zz=1;zz<=test;zz++){
ll i,j,k,n,m;
cin>>n;
vector<int> len(n,0),wid(n,0);
vector<int> v(n,0),w(n,0);//to store widths

for(i=0;i<n;i++)
	cin>>len[i];
for(i=0;i<n;i++)
	cin>>wid[i];
w[0]=v[0]=wid[0];
// v[0]=mp(1,wid[0]);
for(i=1;i<n;i++){
	v[i]=w[i]=wid[i];//the least width that it can have
	for(j=0;j<i;j++){
		if(len[j]<len[i] && v[j]+wid[i]>v[i])//if length is increasing and 
			v[i]=v[j]+wid[i];
		if(len[j]>len[i] && w[j]+wid[i]>w[i])//if length is decreasing and
			w[i]=w[j]+wid[i];
	}
}
int inc=*max_element(v.begin(), v.end());
int dec=*max_element(w.begin(), w.end());
cout<<"Case "<<zz<<". ";
	if(inc>=dec)
		cout<<"Increasing ("<<inc<<"). Decreasing ("<<dec<<").\n";
	else cout<<"Decreasing ("<<dec<<"). Increasing ("<<inc<<").\n";

}
	return 0;
}