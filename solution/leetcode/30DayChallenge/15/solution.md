Problem:
   - [Day15](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3300/)

Tried:
   - `Prefix Sum` based approach

``` c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums;
        
        // left[i] stores prod from nums[0]..nums[i]
        // right[i] stores prod from right[i]..right[n-1]
        vector<int> product(n), left(n, 1), right(n, 1);
        left = nums;    right = nums;   product = nums;
        
        for (int i = 1; i < n; i += 1) 
            left[i] = left[i-1]*nums[i];
        for (int i = n-2; i >= 0; i -= 1)
            right[i] = right[i+1]*nums[i];
        
        product[0] = right[1];
        for (int i = 1; i + 1 < n; i += 1)
            product[i] = left[i-1]*right[i+1];
        product[n-1] = left[n-2];
        
        return product;
    }
};
```
  - Follow up problem
  - Realised that for `product[i]` only `left[i]` and `right[i]` were used
  - All others were not used anymore. This helped in reducing the space complexity.

``` c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prod = 1;
        if (n == 1) return nums;
        
        vector<int> ans = nums;
        for (int i = n-2; i >= 0; i -= 1)
            ans[i] = ans[i+1]*nums[i];
        
        for (int i = 0; i + 1 < n; i += 1) {
            ans[i] = ans[i+1]*prod;
            prod *= nums[i];
        }
        
        ans.back() = prod;
        return ans;
    }
};
```