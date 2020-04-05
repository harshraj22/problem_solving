Problem:
   - [Day5](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3287/)

Tried:
   - ```Basic Dynamic Programming```: &nbsp; O(n) space and time. 
   - P.S. Can be reduced to O(1) space. Think How :) Its not that difficult.

``` c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        
        vector<int> dp[2];
        for (auto &row:dp)
            row.resize(n, 0);
    
        int mx1 = INT_MIN, mx0 = 0;
        
        // dp[0][i] => sells i, cur profit
        for (int i = 0; i < n; i += 1) {
            // buy on 'i'
            dp[1][i] = -prices[i];
            dp[0][i] = 0;
            
            // last should be sold, before buying further
            dp[1][i] = max(dp[1][i], mx0 - prices[i]);
            dp[0][i] = max(dp[0][i], mx1 + prices[i]);
            
            mx0 = max(mx0, dp[0][i]);
            mx1 = max(mx1, dp[1][i]);
            
            // for O(n*n) dp, but clever observation makes it O(n)
            // for (int j = 0; j < i; j += 1) {
            //     dp[1][i] = max(dp[0][j] - prices[i], dp[1][i]);
            //     dp[0][i] = max(dp[1][j] + prices[i], dp[0][i]);
            // }
        }
     
        return *max_element(dp[0].begin(), dp[0].end());
    }
};
```