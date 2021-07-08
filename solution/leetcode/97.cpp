// https://leetcode.com/problems/interleaving-string/


class Solution {
        int n, m, l;
        // (n: s1), (m: s2), (l: s3)
        vector<vector<vector<int>>> dp;
        // (n x m x l)

        bool isSubseq(string &s1, string &s3, int i = 0, int j = 0) {
            // returns if s3 is substring of s1
            if (j >= s3.size())
                return true;
            else if (i >= s1.size())
                return false;
            if (s1[i] == s3[j])
                return isSubseq(s1, s3, i+1, j+1);

            return isSubseq(s1, s3, i+1, j);
        }

        bool recur(int i, int j, int k, string &s1, string &s2, string &s3) {
            // if target string is exhausted
            if (k >= s3.size())
                return true;
            // if this was already calculated
            else if (dp[i][j][k] != -1)
                return dp[i][j][k];
            // if one of the two strings is exhausted
            else if (i >= s1.size() || j >= s2.size())
                return dp[i][j][k] = (isSubseq(s1, s3, i, k) || isSubseq(s2, s3, j, k));

            dp[i][j][k] = (recur(i+1, j, k, s1, s2, s3) || recur(i, j+1, k, s1, s2, s3));
            if (s1[i] == s3[k])
                dp[i][j][k] |= recur(i+1, j, k+1, s1, s2, s3);
            if (s2[j] == s3[k])
                dp[i][j][k] |= recur(i, j+1, k+1, s1, s2, s3);

            return dp[i][j][k];
        }
public:
    bool isInterleave(string s1, string s2, string s3) {

        n = s1.size();
        m = s2.size();
        l = s3.size();

        // initialize the dp table for memoization
        dp.resize(n+1);
        for (auto &row: dp) {
            row.resize(m+1);
            for (auto &col: row)
                col.resize(l+1, -1);
        }

        if (n + m != l) return false;
        return recur(0, 0, 0, s1, s2, s3);
    }
};
