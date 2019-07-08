//	https://www.spoj.com/problems/EDIST/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll table[3003][3003];
string s,ss;	 
ll solve(int i,int j);

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);	cout.tie(0);
int test;	cin>>test;
while(test--){
	 ll i,j,k,n,m;
	 cin>>s>>ss;
	 memset(table,-1,sizeof(table));
	 cout<<solve(0,0)<<"\n";
} 
	return 0;
}

ll solve(int i,int j){
	if(i==s.size())
		return (int)ss.size()-j;
	else if(j==ss.size())
		return (int)s.size()-i;
	else if(table[i][j]!=-1)
		return table[i][j];
	if(s[i]==ss[j])
		return table[i][j]=solve(i+1,j+1);
	return table[i][j]=1+min({solve(i+1,j+1)
						,solve(i+1,j),solve(i,j+1)});

}