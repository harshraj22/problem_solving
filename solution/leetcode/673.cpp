// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        // dp[i]: lenght of longest lis ending at i
        vector<int> dp(n, 1), freq(n, 1);

        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < i; j += 1) {
                if (nums[j] < nums[i]) {
                    if (dp[i] == 1 + dp[j])
                        freq[i] += freq[j];
                    else if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        freq[i] = freq[j];
                    }
                }
            }
        }

        int len = *max_element(dp.begin(), dp.end()), ans = 0;
        for (int i = 0; i < n; i += 1) {
            if (dp[i] == len)
                ans += freq[i];
        }
        return ans;
    }
};