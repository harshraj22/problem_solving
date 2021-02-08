// https://binarysearch.com/problems/Valid-State-of-List

bool solve(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(3, vector<int>(n, 0));

    for (int i = 1; i < n; i += 1) {
        // type0
        if (nums[i] == nums[i-1]) {
            dp[0][i] = true;
            if (i-2 >= 0)
                dp[0][i] &= (dp[0][i-2] || dp[1][i-2] || dp[2][i-2]);
        }

        // type1
        if (i > 1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]) {
            dp[1][i] = true;
            if (i > 2)
                dp[1][i] &= (dp[0][i-3] || dp[1][i-3] || dp[2][i-3]);
        }

        // type2
        if (i > 1 && nums[i] == nums[i-1]+1 && nums[i] == nums[i-2]+2) {
            dp[2][i] = true;
            if (i > 2)
                dp[2][i] &= (dp[0][i-3] || dp[1][i-3] || dp[2][i-3]);
        }
    }

    return dp[0][n-1] || dp[1][n-1] || dp[2][n-1];
}