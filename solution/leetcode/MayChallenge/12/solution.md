Problem: 
   - [Day 12](https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/)

Tried: 
   - Used `Binary Search`
   - Before target element, nums at even index = nums at even+1 index
   - After target element, nums at odd index = nums at odd+1 index

```c++
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();    nums.push_back(nums.back());
        int low = 0, high = n-1;
        if (n == 1) return nums.front();
        
        while (low < high) {
            int mid = (low+high+1)/2;
            // mid is even closest to middle of [low, high]
            if (mid % 2 == 1)
                mid -= 1;
            if (nums[mid] == nums[mid+1])
                low = mid + 2;
            else 
                high = mid;
        }

        return nums[high];
    }
};
```