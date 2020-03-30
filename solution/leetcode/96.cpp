// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    int numTrees(int n) {
        // (a C b) : number of ways of selecting 'a' from 'b'        
        #define ll long long int
        
        // number of unique bst = catalan number = (1/(n+1))*(2n C n)
        vector< vector<ll > > dp (n+1, vector<ll> (2*n +1, 0));
        
        for (int j = 1; j <= 2*n; j += 1) {
            for (int i = 1; i <= min(n,j); i += 1) {
                // dp[i][j] = (j C i)
                if (i == 1) {
                    dp[i][j] = j;
                    continue;
                }
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1];   
            }
        }
        
        return dp[n][2*n]/(n+1);        
    }
};