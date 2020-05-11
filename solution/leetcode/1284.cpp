// https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
// Basic `Dynamic Programming` checking all possible reachable matrices
// Learnt: Unordered_map should have key as an object that is hashable
// unordered_map<vector<int>, int> does't compile as vectors aren't hashable (similar to python)

class Solution {
	#define vii vector<vector<int>>
	map<vii, int> dp;
	vector<pair<int, int>> dir;
	int n, m;

	bool isValid(int i, int j) {
		if (i < 0 || j < 0)
			return false;
		else if (i >= n || j >= m)
			return false;
		return true;
	}

	int recur(vii mat) {
		if (dp.find(mat) != dp.end())
			return dp[mat];
		dp[mat] = 1e6+3;
		int ans = 1e6+5;
		for (int i = 0; i < n; i += 1) {
			for (int j = 0; j < m; j += 1) {
				vii v = mat;
				v[i][j] = 1-v[i][j];
				for (auto it: dir) {
					int x = i + it.first, y = j + it.second;
					if (isValid(x, y))
						v[x][y] = 1-v[x][y];
				}
				ans = min(ans, 1 + recur(v));
			}
		}

		return dp[mat] = ans;
	}

public:
	Solution() {
		dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	}

    int minFlips(vector<vector<int>>& mat) {
		n = mat.size();
		m = mat[0].size();

		vii v(n, vector<int>(m, 0));
		dp[v] = 0;

		recur(mat);
	   	return recur(mat) > 1e5 ? -1: recur(mat); 
    }
};
