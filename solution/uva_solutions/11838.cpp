// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2938

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 2003;

int vertex, edge, numOfComponents;
vector<int> graph[N], revGraph[N];

stack<int> st;
bool vis[N];

void init(){
	for(int i=0;i<N;i++){
		graph[i].resize(0);
		revGraph[i].resize(0);
	}
	numOfComponents = 0;
	while(st.empty() == false)
		st.pop();
	for(int i=0;i<N;i++)
		vis[i] = false;
}

void dfs(int node, int par=0){
	vis[node] = true;
	for(auto it:graph[node]){
		if(vis[it])
			continue;
		dfs(it, node);
	}
	st.push(node);
}

void revDfs(int node, int par=0){
	vis[node] = true;
	for(auto it:revGraph[node]){
		if(vis[it])
			continue;	
		revDfs(it, node);
	}
}

void SCC(){
	for(int i=1;i<=vertex;i++){
		if(vis[i] == false){
			dfs(i);
		}
	}	

	for(int i=0;i<N;i++)
		vis[i] = false;

	while(st.empty() == false){
		int node = st.top();
		st.pop();
		if(vis[node] == true)
			continue;
		revDfs(node);
		numOfComponents += 1;
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	cin >> vertex >> edge;
	while(vertex && edge){
		int from, to, flag;
		init();
		for(int i=0;i<edge;i++){
			cin >> from >> to >> flag;
			graph[from].push_back(to);
			revGraph[to].push_back(from);
			if(flag == 2){
				graph[to].push_back(from);
				revGraph[from].push_back(to);
			}
		}
		SCC();
		if(numOfComponents == 1)
			cout << "1\n";
		else 
			cout << "0\n";

		cin >> vertex >> edge;
	}

	return 0;
}