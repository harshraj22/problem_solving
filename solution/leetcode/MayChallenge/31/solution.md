Problem: 
   - [Day 31](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3346/)

Tried: 
   - Used basic `Dynamic Programming`

```c++
class Solution {
    string s1, s2;
    vector<vector<int>> dp;

    int recur(int l, int r) {
        // convert s1 to s2
        if (l == s1.size()) 
            return (int)s2.size() - r;
        else if (r == s2.size())
            return (int)s1.size() - l;
        else if (dp[l][r] != -1)
            return dp[l][r];
        if (s1[l] == s2[r])
            return dp[l][r] = recur(l+1, r+1);
        return dp[l][r] = 1 + min({recur(l+1, r), recur(l, r+1), recur(l+1, r+1)});
    }

public:
    int minDistance(string word1, string word2) {
        s1 = word1; s2 = word2;
        dp = vector<vector<int>> (s1.size(), vector<int> (s2.size(), -1));
        return recur(0, 0);
    }
};
```