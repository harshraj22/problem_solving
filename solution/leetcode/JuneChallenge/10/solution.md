Problem: 
   - [Day 10](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3356/)

Tried: 
   - Simple `Binary Search`


```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        else if (target > nums.back()) return nums.size();
        return upper_bound(nums.begin(), nums.end(), target) - nums.begin() - binary_search(nums.begin(), nums.end(), target);
    }
};
```