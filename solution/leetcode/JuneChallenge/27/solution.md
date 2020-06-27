Problem: 
   - [Day 27](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/542/week-4-june-22nd-june-28th/3373/)

Tried: 
   - Simple `Dynamic Programming`

```c++
   class Solution {
    int recur(int n, vector<int> &dp) {
        if (n < 0)
            return 1e7;
        else if (dp[n] != -1)
            return dp[n];
        dp[n] = 1e7;
        for (int i = 1; i*i <= n; i += 1)
            dp[n] = min(dp[n], 1+recur(n-i*i, dp));
        return dp[n];
    }
    
public:
    int numSquares(int n) {
        vector<int> dp(n+3, -1);
        dp[0] = 0; dp[1] = 1; dp[2] = 2;
        return recur(n, dp);
    }
};
```
