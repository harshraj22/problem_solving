// https://leetcode.com/problems/wiggle-subsequence/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if (n == 0) return 0;
        vector<vector<int>> dp(2, vector<int> (n, 0));

        // dp[1][i]: ending with downward slope at i
        // larger number creates an upward slope
        for (int i = 1; i < n; i += 1) {
            for (int j = 0; j < i; j += 1) {
                if (nums[i] > nums[j]) 
                    dp[0][i] = max(dp[0][i], 1 + dp[1][j]);
                else if (nums[i] < nums[j]) 
                    dp[1][i] = max(dp[1][i], 1 + dp[0][j]);
            }
            ans = max({ans, dp[0][i], dp[1][i]});
        }

        return ans + 1;
    }
};
