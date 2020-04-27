// https://leetcode.com/problems/maximum-product-subarray/
// A good Dynamic Programming problem

/*
	Idea:
		At any index, the max prod subarray ending at it, is one of the following:
		1. It starts from the given index
		2. It extends the min product subarray ending at index-1
		3. It extends the max product subarray ending at index-1

		Suppose not, i.e. it extends some product subarray ending at index-1, which is
		neither max, nor min, then the product formed using that subarray lies in between
		the product formed using min, max product subarray ending at index-1

	Complexity:
		Space: O(n) can be reduced to O(1) as dp[..][i] uses only dp[..][i-1]
		Time: O(n)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size(), dp[2][n], mx = nums[0];
        
        // dp[0][i] : min prod ending at i
        // dp[1][i] : max prod ending at i
        dp[0][0] = dp[1][0] = nums[0];
        
        for (int i = 1; i < n; i += 1) {
            dp[0][i] = min({nums[i], nums[i]*dp[0][i-1], nums[i]*dp[1][i-1]});
            dp[1][i] = max({nums[i], nums[i]*dp[1][i-1], nums[i]*dp[0][i-1]});
            mx = max({mx, dp[0][i], dp[1][i]});
        }
        
        return mx;
    }
};