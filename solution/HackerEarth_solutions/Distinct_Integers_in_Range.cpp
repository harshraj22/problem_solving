// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/distinct-integers-in-range-66eca44b/

#include<bits/stdc++.h>
using namespace std;
const int bitval=5002;
const int n_val=1e5+2;
vector<int> a(n_val),b(n_val);
vector<bitset<bitval> >sega(4*n_val),segb(4*n_val);
int n;

bitset<bitval> queryb(int node,int left,int right,int lb,int rb){//for query in b
	if(lb>rb)
		return bitset<bitval> (0);
	if(left==lb && right==rb)
		return segb[node];
	bitset<bitval> sa,sb;
	int mid=(left+right)/2;

	sa=queryb(node*2,left,mid,lb,min(rb,mid));
	sb=queryb(node*2+1,mid+1,right,max(lb,mid+1),rb);

	return (sa | sb);
	//count total number of diffrent elements (bitwise or takes care that two distinct elements are counted only once)
}

bitset<bitval> querya(int node,int left,int right,int la,int ra){//for query in a
	if(la>ra)
		return bitset<bitval> (0);
	if(left==la && right==ra)
		return sega[node];
	bitset<bitval> sa,sb;
	int mid=(left+right)/2;

	sa=querya(node*2,left,mid,la,min(ra,mid));
	sb=querya(node*2+1,mid+1,right,max(la,mid+1),ra);

	return (sa | sb);
}

int query(int la,int ra,int lb,int rb){//for total query (just like a wrapper function)
/*	string sa=querya(1,1,n,la,ra);
	string sb=queryb(1,1,n,lb,rb);
	bitset<bitval> saa(sa),sbb(sb);
	saa=saa | sbb;//count from both and merge
	return saa.count();*/

	return (querya(1,1,n,la,ra) | queryb(1,1,n,lb,rb)).count();
}

void builda(int node,int left,int right){
	if(left==right){
		sega[node][a[left]]=1;
		return;
	}
	int mid=(left+right)/2;
	builda(node*2,left,mid);
	builda(node*2+1,mid+1,right);
	sega[node]=(sega[node*2] | sega[node*2+1]);
}

void buildb(int node,int left,int right){
	if(left==right){
		segb[node][b[left]]=1;
		return;
	}
	int mid=(left+right)/2;
	buildb(node*2,left,mid);
	buildb(node*2+1,mid+1,right);
	segb[node]=(segb[node*2] | segb[node*2+1]);
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);

	int i,j,k,m;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>b[i];
	builda(1,1,n);
	buildb(1,1,n);
	cin>>m;
	for(i=0;i<m;i++){
		int la,lb,ra,rb;
		cin>>la>>ra>>lb>>rb;
		cout<<query(la,ra,lb,rb)<<"\n";
	}
	return 0;
}
