// https://leetcode.com/problems/first-missing-positive/
// Store freq using concept of storing 2 numbers at one index, safely handle nums < 0 || num > n

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool available = !(find(nums.begin(), nums.end(), n) == nums.end());
        if (n == 0) return 1;

        for (auto &num: nums) {
            if (num >= n || num <= 0)
                num = 0;
        }

        for (auto num: nums) {
            num %= n;
            if (num == 0) continue;
            int freq = nums[num]/n;
            nums[num] = nums[num]%n + n*(freq+1);
        }

        for (int i = 1; i < n; i += 1) {
            int freq = nums[i]/n;
            if (freq == 0)
                return i;
        }

        return n + available;
    }
};

/*
[1,2,0]
[1,2,3,4]
[2,3,4,5]
*/