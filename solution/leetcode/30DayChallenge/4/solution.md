Problem:
   - [Day4](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3286/)

Tried:
   - ```Two Pointer Method```: &nbsp; O(n)

``` c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, nonZero = 0;
        while(nonZero < n && zero < n) {
            if (nonZero > zero)
                swap(nums[zero], nums[nonZero]);
            else 
                nonZero += 1;
            while(nonZero < n && nums[nonZero] == 0)
                nonZero += 1;
            while (zero < n && nums[zero] != 0)
                zero += 1;
        }
    }
};
```