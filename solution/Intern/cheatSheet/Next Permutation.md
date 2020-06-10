Question [Link](https://leetcode.com/problems/next-permutation/)

Time: O(nlogn) can be updated to O(n) if we do linear search instead of upper_bound (read below)
Space: O(1)

Basic Idea: Iterate from the right and find first point where nums[i] > nums[i-1]. nums[i-1] needs to be changed.
Find the upper_bound of nums[i-1] from the iterated numbers, and swap it with nums[i-1]. Finally sort the iterated nums

```c++
class Solution {
    bool isDecreasing(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i += 1) {
            if (nums[i] > nums[i-1])
                return false;
        }

        return true;
    }

public:
    void nextPermutation(vector<int>& nums) {
        if (isDecreasing(nums)) {
            sort(nums.begin(), nums.end());
            return;
        }

        int n = nums.size();
        for (int i = n-1; i > 0; i -= 1) {
        	// find the rightmost point of inversion
            if (nums[i] > nums[i-1]) {
                sort(nums.begin()+i, nums.end());
                int index = upper_bound(nums.begin()+i, nums.end(), nums[i-1]) - nums.begin();
                swap(nums[i-1], nums[index]);
                sort(nums.begin()+i, nums.end());
                break;
            }
        }
    }
};
```
