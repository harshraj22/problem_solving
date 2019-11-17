// https://www.hackerrank.com/contests/data-structure-tasks-binary-tree-union-find/challenges/connected-component/problem

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int nodes = 0;
vector<int> par, weight;

int find_par(int index){
	if(index == par[index])
		return index;
	return par[index] = find_par(par[index]);
}

void Merge(int u, int v){
	int up = find_par(u), vp = find_par(v);
	if(weight[up] > weight[vp]){
		weight[up] += weight[vp];
		par[vp] = up;
	}
	else{
		weight[vp] += weight[up];
		par[up] = vp;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> nodes;
	par.resize(nodes+3);
	weight.resize(nodes+3,1);
	iota(par.begin(), par.end(), 0);

	int components = nodes;
	int u,v;
	while(cin >> u >> v){
		int up = find_par(u), vp = find_par(v);
		if(vp == up){
			cout << components << " CYCLE FORMED!\n";
		}
		else{
			components -= 1;
			Merge(u,v);
			cout << components << "\n";
		}
	}

	return 0;
}