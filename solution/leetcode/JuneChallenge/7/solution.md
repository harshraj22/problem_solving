Problem: 
   - [Day 5](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3353/)

Tried: 
   - Standard `Dynamic Programming`


```c++
class Solution {
    int n;  
    vector<vector<int>> dp;
    vector<int> coins;

    int recur(int amt, int index) {
        if (amt < 0) 
            return 0;
        else if (amt == 0)
            return 1;
        else if (index < 0)
            return 0;
        else if (dp[amt][index] != -1)
            return dp[amt][index];
        return dp[amt][index] = recur(amt-coins[index], index) + recur(amt, index-1);
    }

public:
    int change(int amount, vector<int>& c) {
        coins = c;
        n = coins.size();
        dp = vector<vector<int>> (amount+1, vector<int> (n+1, -1));

        return recur(amount, n-1);
    }
};
```