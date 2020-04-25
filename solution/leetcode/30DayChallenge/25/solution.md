Problem:
   - [Day25](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3310/)

Tried:
   - Used `Dynamic Programming` with `Prefix Sum`
   - O(n) space and Time, O(n2) time DP fails

``` c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> dp(n, false);
        vector<int> suffix_sum(n, 0);
        dp.back() = true;   suffix_sum.back() = 1;
        
        for (int i = n-2; i >= 0; i -= 1) {
            suffix_sum[i] = suffix_sum[i+1];
            if (nums[i] > 0) {
                int lastIndex = min(n-1, i+nums[i]);
                int numOfOne = suffix_sum[i+1] - suffix_sum[lastIndex] + dp[lastIndex];
                dp[i] = numOfOne;
                suffix_sum[i] += dp[i];
            } 
        }
        
        return dp[0];
    }
};
```