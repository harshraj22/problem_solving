Problem:
   - [Day19](https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3304/)

Tried:
   - Basic `Binary Search`

``` c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;

        // pivot is index which contains largest value
        int pivot;
       
        // array is not sorted, find pivot
        int left = 0, right = (int)nums.size() -1;
        while(left + 1 < right) {
            int mid = (left + right)/2;
            if (nums[mid] > nums[left])
                left = mid;
            if (nums[mid] < nums[right])
                right = mid;
        }
        
        pivot = left;
        // if target lies in first part
        if (binary_search(nums.begin(), nums.begin()+pivot+1, target))
            return lower_bound(nums.begin(), nums.begin()+pivot+1, target) - nums.begin();
        // if target lies in second part
        else if (binary_search(nums.begin()+pivot+1, nums.end(), target))
            return lower_bound(nums.begin()+pivot+1, nums.end(), target) - nums.begin();
        // if target is not present
        return -1;
    }
};
```