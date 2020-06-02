// https://leetcode.com/problems/sort-colors/
// Two pointer, One pass, O(1) space, O(n) Time

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // first: index at which next 0 is to be placed
        // second: index at which next 1 is to be placed
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