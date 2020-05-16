// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
    int dp[1001][1001];
    string s;

    int get(int l, int r) {
        if (dp[l][r] != -1)
            return dp[l][r];
        else if (l == r) 
            return dp[l][r] = 1;
        else if (l > r)
            return dp[l][r] = 0;
        dp[l][r] = max(get(l+1, r), get(l, r-1));
        if (s[l] == s[r]) 
            dp[l][r] = max(dp[l][r], 2 + get(l+1, r-1));
        return dp[l][r];
    }

public:
    Solution() {
        for (int i = 0; i < 1001; i += 1) {
            for (int j = 0; j < 1001; j += 1)
                dp[i][j] = -1;
        }
    }

    int longestPalindromeSubseq(string str) {
        s = str;
        return get(0, (int)s.size()-1);
    }
};