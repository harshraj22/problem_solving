Problem:
   - [Day3](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3285/)

Tried:
   - ```kadane's algo```: &nbsp; O(n)

``` c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN, cur_sum = 0, left = 0, right = 0, n = nums.size();
        
        while (right < n) {
            while (left < right && cur_sum < 0) {
                cur_sum -= nums[left];
                left += 1;
            }
            cur_sum += nums[right];
            right += 1;
            sum = max(sum, cur_sum);
        }
        
        while (left + 1 < n) {
            cur_sum -= nums[left];
            left += 1;
            sum = max(sum, cur_sum);
        }
        
        return sum;
    }
};
```

   - ```Divide & Conquer```: &nbsp; O(nlogn)
``` c++
class Solution {
public:
    int Divide(int left, int right, vector<int> &nums) {
        if (left + 1 == right)
            return nums[left];
        else if (left + 2 == right) {
            return max({nums[left], nums[left+1], nums[left]+nums[left+1]});
        }
        
        int mid = left + (right - left)/2;
        int left_sum = INT_MIN, right_sum = INT_MIN, cur_sum = 0;
        
        for (int i = mid; i < right; i += 1) {
            cur_sum += nums[i];
            right_sum = max(right_sum, cur_sum);
        }
        
        cur_sum = 0;
        for (int i = mid-1; i >= 0; i -= 1) {
            cur_sum += nums[i];
            left_sum = max(left_sum, cur_sum);
        }
        
        return max({left_sum+right_sum, Divide(left, mid, nums), Divide(mid,right, nums)});
    }
    
    int maxSubArray(vector<int>& nums) {
        return Divide(0, (int)nums.size(), nums);
    }
};
```