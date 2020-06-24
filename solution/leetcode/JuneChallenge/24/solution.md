Problem: 
   - [Day 24](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3370/)

Tried: 
   - Good `Dynamic Programming` + `BST Properties`


```c++
class Solution {
    // number of bst using [a, a+1, a+2, .., a+k] is same as
    // number of bst using [0, 1, 2, .., k]

    int recur(int n, vector<int> &dp) {
        if (n < 0)
            return 0;
        else if (dp[n] != -1)
            return dp[n];
        dp[n] = 0;

        // 'i' is root, number of such bst, build left and right child
        for (int i = 1; i <= n; i += 1) 
            dp[n] += (recur(i-1, dp) * recur(n-i, dp));

        return dp[n];
    }

public:
    int numTrees(int n) {
        // base case
        if (n < 3) return n;
        vector<int> dp(n+1, -1);

        dp[0] = dp[1] = 1; 
        dp[2] = 2;

        return recur(n, dp);
    }
};
```
