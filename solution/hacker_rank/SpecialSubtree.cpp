// https://www.hackerrank.com/challenges/primsmstsub/problem

#include<bits/stdc++.h>
using namespace std;

ofstream fout(getenv("OUTPUT_PATH"));
#define cout fout

#define ll long long int
const int N = 3e3+5;
#define pi pair<ll, ll>
#define pii pair<ll, pi>

// vector of (weight, node)
vector<pi> gr[N];
priority_queue< pii, vector<pii>, greater<pii> > pq;
ll n,m;

vector<int> weighted_rank(N,1), parent(N);

ll find_parent(int x){
	if(x == parent[x])
		return x;
	return parent[x] = find_parent(parent[x]);
}

void join(int x, int y){
	ll xp = find_parent(x), yp = find_parent(y);
	if(weighted_rank[xp] > weighted_rank[yp]){
		// make xp as parent
		parent[yp] = xp;
		weighted_rank[yp] += weighted_rank[xp];
	}
	else{
		parent[xp] = yp;
		weighted_rank[xp] += weighted_rank[yp];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x, y, r;
		cin >> x >> y >> r;
		gr[x].push_back(make_pair(r, y));
		gr[y].push_back(make_pair(r, x));
		pq.push(make_pair(r, make_pair(x, y)));
	}

	int variable;
	cin >> variable;

	iota(parent.begin(), parent.end(), 0);

	ll sum = 0;

	while(pq.empty() == false){
		auto all = pq.top();
		pq.pop();
		ll weight = all.first, edge1 = all.second.first, edge2 = all.second.second;
		if(find_parent(edge1) == find_parent(edge2))
			continue;
		else{
			sum += weight;
			join(edge1, edge2);
		}
	}

	cout << sum << '\n';

	return 0;
}