// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

class Solution {
    const static int mod = 1e9 + 7;
public:
    int countOrders(int n) {
        vector<long long int > dp(n+1, 1);
        for (int i = 2; i <= n; i += 1) {
            dp[i] = dp[i-1]*((2*i-1) + (i-1)*(2*i-1));
            dp[i] %= mod;
        }

        return dp.back() % mod;
    }
};