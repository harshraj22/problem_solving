Problem: 
   - [Day 11](https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/540/week-2-june-8th-june-14th/3357/)

Tried: 
   - Basic Logic


```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int first = 0, second = 0;
        for (int i = 0; i < nums.size(); i += 1) {
            int num = nums[i];
            nums[i] = 2;
            if (num == 0) {
                if (first < second) {
                    nums[second] = 1;
                    second += 1;
                }
                nums[first] = 0;
                first += 1;
            }
            else if (num == 1) {
                nums[second] = 1;
                second += 1;
            }
            second = max(second, first);
        }
    }
};
```