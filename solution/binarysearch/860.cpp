// https://binarysearch.com/problems/Non-Adjacent-Combination-Sum

// Standard DP: Knapsack
// Time & Space O(n*k)

int n, k;
vector<vector<int>> dp;
vector<int> nums;

int build(int index, int sum) {
	// base case
	if (index < 0) 
		return sum == 0;
	else if (sum <= 0)
		return sum == 0;
	else if (dp[index][sum] != -1)
		return dp[index][sum];

	// calculate
	return dp[index][sum] = max(build(index-1, sum), build(index-2, sum-nums[index]));
}

bool solve(vector<int>& Nums, int K) {
    nums = Nums;
    n = nums.size();
    k = K;
    dp = vector<vector<int>> (n+1, vector<int> (k+1, -1));

    return build(n-1, k) == 1;
}