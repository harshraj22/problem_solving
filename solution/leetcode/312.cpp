// https://leetcode.com/problems/burst-balloons/

// Matrix Chain Multiplication DP
// Time: O(n*n*n), Space: O(n*n)

class Solution {
    int n;
    vector<vector<int>> dp;
    
    // get answer for range (nums[left], nums[right]) where extremes are excluded
    int getCoin(int left, int right, vector<int> &nums) {
        if (dp[left][right] != -1)
            return dp[left][right];
        else if (right - left == 2)
            return dp[left][right] = nums[left]*nums[left+1]*nums[right];
        else if (right-left < 2)
            return 0;
        
        dp[left][right] = 0;
        // if nums[i] is the last remaining in range (nums[left], nums[right]) extremes excluded
        for (int i = left+1; i < right; i += 1) 
            dp[left][right] = max(dp[left][right], 
            		nums[i]*nums[left]*nums[right] + getCoin(left, i, nums) + getCoin(i, right, nums));
        
        return dp[left][right];
    }
    
public:
    int maxCoins(vector<int>& nums) {
        n = nums.size();
        dp = vector<vector<int>> (n+2, vector<int> (n+2, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return getCoin(0, n+1, nums);
    }
};