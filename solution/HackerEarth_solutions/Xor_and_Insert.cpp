#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
struct trie{
	ll num=0;
	// map<ll,trie* > lk;
	trie* lk[2]={nullptr};
 
};
 
trie* root=nullptr;
 
trie* get(){
	trie* temp =new trie;
	temp->num=0;
	temp->lk[0]=temp->lk[1]=nullptr;
	return temp;
}
 
void add(ll n){
	if(root==nullptr)root=get();
	trie* node=root;
	for(ll i=32;i>=0;i--){
		ll val=(n & 1LL<<i)?1:0;
		if(node->lk[val]==nullptr)
			node->lk[val]=get();
		node=node->lk[val];
	}
	node->num=n;
}
 
ll search(ll n){
	if(root==nullptr || n==0)return 0;
	trie* node=root;
	for(ll i=32;i>=0;i--){
		ll val=(n & 1LL<<i)?1:0;
		if(node->lk[val]==nullptr)
			node=node->lk[1-val];
		else node=node->lk[val];
	}
	return node->num;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	ll i,j,k,n,m=0;
	cin>>n;	add(0);
	while(n--){
		cin>>j;
		if(j==3)cout<<(m^search(m))<<"\n";
		else cin>>k;
 
		if(j==1)add(k^m);
		else if(j==2)m^=k;
	}
 
	return 0;
}