// https://leetcode.com/problems/integer-break/

class Solution {
    vector<long long int> dp;

    long long int get(int n) {
        if (dp[n] != -1)
            return dp[n];
        else if (n < 3)
            return n;
        dp[n] = n;
        for (int i = 1; i < n; i += 1) 
            dp[n] = max(dp[n], get(n-i)*i);
        return dp[n];
    }
    
public:
    Solution() {
        dp.resize(1000001);
        fill(dp.begin(), dp.end(), -1);
    }
    
    int integerBreak(int n) {
        long long int ans = 0;
        for (int i = 1; i < n; i += 1) 
            ans = max(ans, get(n-i)*i);        
        return ans;
    }
};