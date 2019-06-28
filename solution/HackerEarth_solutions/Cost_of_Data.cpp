#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll cnt=0;

struct trie{
	bool eow=false;
	trie* lk[26]={nullptr};
};

trie* root=nullptr;

trie* get(){
	trie* temp=new trie;
	temp->eow =false;
	for(auto &it:temp->lk)
		it={nullptr};
	cnt++;
	return temp;
}

void insert(string s){
	if(root ==nullptr)root=get();
	trie* temp=root;
	for(auto it:s){
		if(temp->lk[it-'a']==nullptr)
			temp->lk[it-'a']=get();
		temp=temp->lk[it-'a'];
	}
	temp->eow=true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int i,j,k,n,m;
	cin>>n;
	while(n--){
		string s;
		cin>>s;	insert(s);
	}
	cout<<cnt<<"\n";
	return 0;
}