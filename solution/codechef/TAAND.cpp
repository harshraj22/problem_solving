// https://www.codechef.com/LTIME14/problems/TAAND

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
pair<int,int> ans={0,0};

struct trie{
	int num;
	trie* ar[2]={nullptr};
};

trie* root=nullptr;

trie* get(){
	trie* temp=new trie;
	temp->num=0;
	return temp;
}

void insert(int n){
	if(root==nullptr)root=get();
	trie* node=root;
	for(int i=32;i>=0;i--){
		int var=(n & 1LL<<i)?1:0;
		if(node->ar[var]==nullptr)
			node->ar[var]=get();
		node=node->ar[var];
	}
	node->num=n;
}

void update(int n){
	if(root==nullptr)return;
	trie* node=root;
	for(int i=32;i>=0;i--){
		int var=(n & 1LL<<i)?1:0;
		if(node->ar[var]==nullptr)
			node=node->ar[1-var];
		else node=node->ar[var];
	}
	// ans={node->num,n};
	if((node->num & n)>(ans.first & ans.second))
		ans={node->num , n};
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	ll i,j,k,n,m;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;	update(j);
		insert(j);
	}
	// cout<<ans.first<<" "<<ans.second<<"\n";
	cout<<(ans.first & ans.second)<<"\n";
	return 0;
}
