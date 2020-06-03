Problem: 
   - [Day 3](// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3349/)

Tried: 
   - Standard `Dynamic Programming`


```c++
class Solution {
    vector<vector<int>> costs, dp;
    int n;

    // numInA: (number of passengers) + 1 required in A
    // total: (total number of passengers) + 1 required
    int recur(int numInA, int total) {  
        if (numInA > total) // We have sent more passengers to B than its capacity
            return 1e8; // Return Infinity, this choise will be thus neglected while calculating
        else if (numInA == -1) {  // no more passengers required in A
            int sum = 0;
            for (int i = 0; i <= total; i += 1)
                sum += costs[i][1];
            return sum;
        }
        else if (dp[numInA][total] != -1) // result calculated previously
            return dp[numInA][total];
        else if (numInA == total) { // if all passengers are to be in A
            int sum = 0;
            for (int i = 0; i <= total; i += 1) 
                sum += costs[i][0];
            return dp[numInA][total] = sum;
        }

        // min of: (current passenger goes A), (current passenger goes B)
        return dp[numInA][total] = min(costs[total][0] + recur(numInA-1, total-1), costs[total][1] + recur(numInA, total-1));
    }

public:
    int twoCitySchedCost(vector<vector<int>>& c) {
        costs = c; n = c.size() / 2;
        dp = vector<vector<int>> (2*n, vector<int> (2*n, -1));
        return recur(n-1, 2*n-1);
    }
};
```