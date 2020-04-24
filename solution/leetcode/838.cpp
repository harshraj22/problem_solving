// https://leetcode.com/problems/push-dominoes/
// Simple DP based solution

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = '.' + dominoes + '.';
        int n = dominoes.size();    string ans;
        vector<vector<int>> dp(2, vector<int>(n, -1));
        
        for (int i = 0; i < n; i += 1) ans += '.';
        
        // dp[0][i] = last left falling after or at 'i', i.e. right
        for (int i = 1; i < n; i += 1) {
            dp[0][i] = dp[0][i-1];
            dp[0][i] = (dominoes[i-1] == 'L') ? -1: dp[0][i];
            dp[0][i] = (dominoes[i] == 'R') ? i: dp[0][i];
        }
        
        for (int i = n-2; i > 0; i -= 1) {
            dp[1][i] = dp[1][i+1];
            dp[1][i] = (dominoes[i+1] == 'R') ? -1: dp[1][i];
            dp[1][i] = (dominoes[i] == 'L') ? i: dp[1][i];
        }
        
        for (int i = 1; i < n; i += 1) {
            if ((i-dp[0][i] == dp[1][i]-i && dp[0][i] != -1 && dp[1][i] != -1)
                        || dp[0][i]+dp[1][i] == -2)
                continue;
            else if (dp[0][i] == -1)
                ans[i] = 'L';
            else if (dp[1][i] == -1)
                ans[i] = 'R';
            else {
                ans[i] = (i-dp[0][i] > dp[1][i] -i) ? 'L': 'R';
            }
        }
        
        return ans.substr(1, (int)ans.size()-2);
    }
};
