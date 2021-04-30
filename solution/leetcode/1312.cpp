// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
    int n;
    vector<vector<int>> dp;

    int recur(int l, int r, string &s) {
        if (l==r) return 0;
        else if (dp[l][r] != -1)
            return dp[l][r];
        else if (l+1 == r) 
            return dp[l][r] = (s[l] == s[r] ? 0: 1);
        return dp[l][r] = (s[l] == s[r] ? recur(l+1, r-1, s): 1 + min(recur(l+1, r, s), recur(l, r-1, s)));
    }

public:
    int minInsertions(string s) {
        n = s.size();
        dp = vector<vector<int>> (n, vector<int> (n, -1));

        return recur(0, n-1, s);
    }
};