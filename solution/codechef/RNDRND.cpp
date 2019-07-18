#pragma warning(disable:4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);

#define ll long long int 
#define eb emplace_back

const int inf = 0x3f3f3f3f;
const ll INF = 0xFFFFFFFFFFFFFFFL;
const int N=1e3+3;

int n,m;
vector<int> pr;

bool is_possible(int step){
	bool pos=false;
	for(int gap=1;gap<=n;gap++){
		set<int> st;
		for(int ste=step,index=1;ste>0;ste--){
			if(binary_search(pr.begin(), pr.end(),index))
				st.insert(index);
			index = (index+gap-1)%n+1;
		}
		if(st.size()==m)
			pos=true;
	}
	return pos;
}

int main(){
	IOS;
	int i,j,k=0;
	cin>>n>>m;	pr.reserve(m);
	for(i=0;i<m;i++){
		cin>>j;	pr.eb(j);
	}
	int low=0,high=n;
	while(low<high){
		int step=(low+high)/2,var=step,index=1;
		if(is_possible(step))
			high=step;
		else low=step+1;
	}
	cout<<high<<'\n';
	return 0;
}