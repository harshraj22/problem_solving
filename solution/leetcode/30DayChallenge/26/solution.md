Problem:
   - [Day26](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3311/)

Tried:
   - Used standard `Dynamic Programming` O(n2) space and time

``` c++
class Solution {
public:
    vector<vector<int> > dp;
    int n, m;
    string s1, s2;
    
    int recur(int l, int r) {
        if (l < 0 || r < 0)
            return 0;
        else if (dp[l][r] != -1)
            return dp[l][r];
        
        if (s1[l] == s2[r])
            return dp[l][r] = 1 + recur(l-1, r-1);
        return dp[l][r] = max(recur(l-1, r), recur(l, r-1));        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        
        s1 = text1;
        s2 = text2;
        
        dp.resize(n);
        for (auto &it:dp)
            it.resize(m);
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < m; j += 1)
                dp[i][j] = -1;
        }
        
        return recur(n-1, m-1);
    }
};
```

   - Python3 solution
```python
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n, m = len(text1), len(text2)
        if min(n, m) == 0:
            return 0
        
        dp = [[-1 for i in text2] for j in text1]
        
        def recur(first, second):
            if min(first, second) < 0:
                return 0
            elif dp[first][second] != -1:
                return dp[first][second]
            
            dp[first][second] = 1 + recur(first-1, second-1) if text1[first] == text2[second] else max(recur(first-1, second), recur(first, second-1))
            return dp[first][second]
        
        return recur(n-1, m-1)
        
```