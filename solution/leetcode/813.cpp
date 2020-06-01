// https://leetcode.com/problems/largest-sum-of-averages/

class Solution {
    vector<vector<double>> dp;
    vector<int> scores;
    int n;

    double recur(int numGrp, int index) {
        if (numGrp == 1) 
            return dp[index][numGrp] = accumulate(scores.begin()+index, scores.end(), (double)0) / (n-index);
        else if (index == n)
            return 0;
        else if (dp[index][numGrp] >= 0)
            return dp[index][numGrp];
        dp[index][numGrp] = -1e6;
        for (int i = index, sum = 0; i < n; i += 1) {
            sum += scores[i];
            dp[index][numGrp] = max(dp[index][numGrp], sum*1.0/(i-index+1) + recur(numGrp-1, i+1));
        }

        return dp[index][numGrp];
    }

public:
    double largestSumOfAverages(vector<int>& A, int k) {
        n = A.size();   scores = A;
        dp = vector<vector<double>> (n+1, vector<double> (k+1, -1));
        
        return recur(k, 0);
    }
};