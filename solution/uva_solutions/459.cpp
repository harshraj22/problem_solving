// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int par[26];

int find_par(int u){
	if(par[u]==u)return u;
	return par[u]=find_par(par[u]);
}

void join(int u,int v){
	int uu=find_par(u),vv=find_par(v);
	if(uu!=vv)
		par[uu]=vv;
}

int main(){
int test;	cin>>test;
while(test--){
	for(int i=0;i<26;i++)par[i]=i;
	char ch;	int i,j,k,n,m=0;	string s;
	cin>>ch;	n=ch-'A';/*	cout<<n<<"---\n";*/
	cin.ignore();
	while(getline(cin,s) && !s.empty()){
		int u=s[0]-'A', v=s[1]-'A';
		join(u,v);/*	cout<<u<<" = "<<v<<"\n";*/
	}
	for(i=0;i<=n;i++)
		m+=(par[i]==i);
	cout<<m<<"\n";
	if(test)cout<<"\n";
}
	return 0;
}