// https://www.codechef.com/problems/CATS
// My first binary-lifting solution completely owned by me ^_^
#include<bits/stdc++.h>
using namespace std;
#define log log2

const int N = 3e5 + 5;
const int LG = log(N) + 1;

int n, lg, ans = 0;
vector<int> parent, catNode, depth;
// dp[node][i] stores the '2^i' the parent
// of 'node' in the given tree
vector<vector<int> > dp, graph;
vector<bool> isCatPresent;

void dfs(int node, int par=0) {
	// update current node's depth
	depth[node] = depth[par] + 1;

	// fill dp table for current node
	dp[node][0] = par;
	for (int i = 1; i <= lg; i += 1) {
		int x = dp[node][i-1];
		dp[node][i] = dp[x][i-1];
	}

	// recur for current node's children
	for (auto child: graph[node]) {
		if (child == par)
			continue;
		dfs(child, node);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	cin >> n;
	lg = log(n) + 1;

	parent.resize(n+1);
	catNode.resize(n+1);
	graph.resize(n+1);
	dp.resize(n+1);
	depth.resize(n+1);
	isCatPresent.resize(n+1, 0);
	
	for (auto &it:dp)
		it.resize(lg+1, 0);

	for (int i = 1; i <= n; i += 1) {
		cin >> parent[i];
		graph[parent[i]].push_back(i);
	}

	for (int i = 1; i <= n; i += 1)
		cin >> catNode[i];

	int root = find(parent.begin()+1, parent.end(), 0) - parent.begin();
	dfs(root);

	// so that each cat stops after (if) going to root
	isCatPresent[0] = 1;

	for (int i = 1; i <= n; i += 1) {
		int targetNode = catNode[i], ans = 0;
		// if cat doesn't climb the tree at all
		if (isCatPresent[targetNode]) {
			cout << 0 << '\n';
			continue;
		}

		ans += 1;
		for (int j = lg; j >= 0; j -= 1) {
			// say the cat can climb maxDist '00101010',
			// iterate through left side, if you try from 
			// right side, you might end up at something like
			// '0000111' as the next '2^i' is too large
			// note that we make a jump by chcking if a cat is
			// present there or not, and for each height < maxDist
			// there will be no cat, hence if we iterate from right
			// side, we will make a jump on each bit, not giving
			// us the most optimal answer.

			// consider leftmost set bit (say i):
			// if we could make 2 jumps of '2^i', we would have
			// instead made a jump of '2^(i+1)'
			if (isCatPresent[dp[targetNode][j]])
				continue;
			ans += (1 << j);
			targetNode = dp[targetNode][j];
		}
		isCatPresent[targetNode] = 1;
		cout << ans << '\n';
	}

	return 0;
}