Problem: 
   - [Day 25](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3340/)

Tried: 
   - Used basic `Dynamic Programming`

```c++

class Solution {
    vector<vector<int>> dp;
    vector<int> a, b;
    int recur(int first, int second) {
        if (first >= dp.size() || second >= dp[0].size())
            return 0;
        else if (dp[first][second] != -1)
            return dp[first][second];
        dp[first][second] = (a[first] == b[second]);
        return dp[first][second] = max({dp[first][second] + recur(first+1, second+1), recur(first+1, second), recur(first, second+1)});
    }

public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        a = A; b = B;
        int n = A.size(), m = B.size();
        dp.resize(n, vector<int> (m, -1));
        for (auto &row: dp) {
            for (auto &element: row)
                element = -1;
        }

        return recur(0, 0);
    }
};
```