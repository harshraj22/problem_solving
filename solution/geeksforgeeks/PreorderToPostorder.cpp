// https://practice.geeksforgeeks.org/problems/preorder-to-postorder/0
// Idea used: Properties of BST

#include<bits/stdc++.h>
using namespace std;

vector<int> convert(vector<int> preorder) {
	if (preorder.size() <= 1)
		return preorder;

	// left: left-subtree, right: right-subtree
	vector<int> left, right;
	for (auto node: preorder) {
		if (node < preorder.front())
			left.push_back(node);
		else if (node > preorder.front())
			right.push_back(node);
	}

	left = convert(left);
	right = convert(right);

	// return left + right + [preorder.front()];
	copy(right.begin(), right.end(), back_inserter(left));
	left.push_back(preorder.front());
	return left;
}


void solve() {
	int n;	cin >> n;
	vector<int> preorder(n);
	for (auto &node: preorder) 
		cin >> node;

	preorder = convert(preorder);
	for (auto node: preorder)
		cout << node << ' ';
	cout << endl;
}

int main() {
	int test;	cin >> test;
	while (test--)
		solve();

	return 0;
}
