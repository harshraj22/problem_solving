#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define eb emplace_back
const int N=2e5+4;
int n,q,depth[N],ans_query[N],query[N];
vector<int> g[N],down_query[N];
set<int> up_query[N];
 
// answer queries offline using single dfs
// down_query stores idexes of queries from the given index(source)
// query stores depth from the source of the given query index
// up_query stores indexes of queries for which the current node is one of the answer
 
void dfs1(int node,int par,int dep);
void dfs2(int node,int par);
 
int main(){
	cin>>n>>q;
	for(int i=1,to,from;i<n;i++){//store graph
		cin>>to>>from;
		g[to].eb(from),g[from].eb(to);
	}
	dfs1(1,0,0);	//mark depths of all nodes
	for(int i=1,source,dep;i<=q;i++){//store queries
		cin>>source>>dep;
		down_query[source].eb(i);
		query[i]=dep;
	}
	dfs2(1,0);//find answer to queries
	for(int i=1;i<=q;i++)
		cout<<ans_query[i]<<"\n";
 
	return 0;
}
 
void dfs2(int node,int par){
	for(auto it:up_query[depth[node]]){//all the query indexes to which the current node is answer
		ans_query[it]++;
	}
	for(auto it:down_query[node]){//contains query number
		int dep=query[it];	//depth from given source
		dep+=depth[node];//depth from root
		up_query[dep].insert(it);//in the current subtree,at given depth,the node is answer to it'th query		
	}
	for(auto it:g[node]){
		if(it==par)
			continue;
		dfs2(it,node);
	}
	for(auto it:down_query[node]){//contains query number
		int dep=query[it];
		dep+=depth[node];
		up_query[dep].erase(it);//it'th query is complete as we are not allowed to go towards root and all subnodes have been visited 
	}
}
 
void dfs1(int node,int par,int dep){
	for(auto it:g[node]){
		if(it==par)
			continue;
		dfs1(it,node,dep+1);
	}
	depth[node]=dep;//store depth of all nodes
}
 
/*
 
1 3
1 0
1 1
1 2
 
7 4
1 2 1 3 2 4 2 5 3 6 3 7
1 3
4 1
1 2
1 1
5 3
1 2 2 3 3 4 4 5
1 5
1 2 
2 1
 
*/ 